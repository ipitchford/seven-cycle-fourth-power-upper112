#pragma once
// Necessary partition CSP for two independent size-33 C7^3 bands at distance
// 2 or 3. Exact unsigned 128-bit masks carry the 66 Boolean variables.
#include <algorithm>
#include <array>
#include <chrono>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
namespace partition113 {
using U=std::uint64_t;using Bits=unsigned __int128;
using Code=std::array<std::uint16_t,33>;
using Pair=std::array<U,2>;
constexpr Bits FULL=(Bits(1)<<66)-1,GROUP=(Bits(1)<<33)-1;
inline unsigned pop(Bits x){return __builtin_popcountll(U(x))+__builtin_popcountll(U(x>>64));}
inline unsigned low(Bits x){return U(x)?__builtin_ctzll(U(x)):64+__builtin_ctzll(U(x>>64));}
inline U mix(U x){x^=x>>30;x*=0xbf58476d1ce4e5b9ULL;x^=x>>27;x*=0x94d049bb133111ebULL;return x^(x>>31);}
inline U hashbits(Bits x){return mix(U(x))^mix(U(x>>64)+0x9e3779b97f4a7c15ULL);}
struct PairHash {size_t operator()(const Pair&p)const{return mix(p[0])^mix(p[1]+0x9e3779b97f4a7c15ULL);}};
struct BitsHash {size_t operator()(Bits x)const{return hashbits(x);}};
struct State {Bits mask=0,on=0;bool operator==(const State&s)const{return mask==s.mask&&on==s.on;}};
struct StateHash {size_t operator()(const State&s)const{return hashbits(s.mask)^mix(hashbits(s.on));}};
using StateSet=std::unordered_set<State,StateHash>;
using Dictionary=std::array<std::unordered_map<Pair,std::vector<Pair>,PairHash>,4>;
inline std::array<int,3> digits(unsigned v){return {int(v/49),int(v/7%7),int(v%7)};}
inline bool confusable(const std::array<int,3>&a,const std::array<int,3>&b){for(int k=0;k<3;++k){int d=(a[k]-b[k]+7)%7;if(d!=0&&d!=1&&d!=6)return false;}return true;}
inline void validate(const Code&c){for(int i=0;i<33;++i){if(c[i]>=343)throw std::runtime_error("word range");for(int j=0;j<i;++j)if(confusable(digits(c[i]),digits(c[j])))throw std::runtime_error("nonindependent band");}}
inline std::string decimal(Bits x){if(!x)return "0";std::string s;while(x){s.push_back('0'+x%10);x/=10;}std::reverse(s.begin(),s.end());return s;}
struct Limits {size_t joined=250000,models=20000,completed=1000000;std::chrono::steady_clock::time_point deadline=std::chrono::steady_clock::time_point::max();};
struct Result {
 bool complete=false;std::string reason;std::vector<Bits> models;
 std::array<size_t,3> joined{};std::vector<size_t> successive;
 std::array<int,3> order{};U operations=0,fill_nodes=0;
};
struct Bounded:std::runtime_error{using std::runtime_error::runtime_error;};
class Solver {
 const Dictionary& dict;Limits limits;int distance=0;Result result;
 std::array<State,132> closures{};std::array<bool,132> closure_ok{};
 std::unordered_set<Bits,BitsHash> models;StateSet completed;
 static bool join(const State&a,const State&b,State&out){if((a.on^b.on)&a.mask&b.mask)return false;out={a.mask|b.mask,a.on|b.on};return true;}
 void tick(){if((++result.operations&1023)==0&&std::chrono::steady_clock::now()>limits.deadline)throw Bounded("deadline");}
 bool possible(const State&s)const{
  unsigned lo0=pop(s.on&GROUP),lo1=pop(s.on>>33);
  unsigned hi0=33-pop((s.mask&~s.on)&GROUP),hi1=33-pop((s.mask&~s.on)>>33);
  auto card=[&](unsigned a,unsigned b){return lo0<=a&&a<=hi0&&lo1<=b&&b<=hi1;};
  unsigned a0=std::max(lo0,14u),a1=std::max(lo1,14u);
  unsigned b0=std::min(hi0,19u),b1=std::min(hi1,19u);
  return a0<=b0 && a1<=b1 && (distance==3 || b0>=a1);
 }
 bool close(State in,State&out){out={};for(Bits m=in.mask;m;m&=m-1){unsigned v=low(m),lit=2*v+bool(in.on&(Bits(1)<<v));if(!closure_ok[lit])return false;State next;if(!join(out,closures[lit],next))return false;out=next;}return possible(out);}
 void fill(const State&s){
  ++result.fill_nodes;tick();if(!possible(s)||completed.count(s))return;
  if(s.mask==FULL){models.insert(s.on);if(models.size()>limits.models)throw Bounded("model cap");}
  else{
   int chosen=-1,best=-1;
   for(Bits m=FULL&~s.mask;m;m&=m-1){unsigned v=low(m);int score=0;for(int b=0;b<2;++b)if(closure_ok[2*v+b])score+=pop(closures[2*v+b].mask&~s.mask);if(score>=best){best=score;chosen=v;}}
   for(int b=0;b<2;++b){unsigned lit=2*chosen+b;State next;if(closure_ok[lit]&&join(s,closures[lit],next))fill(next);}
  }
  if(completed.size()>=limits.completed)throw Bounded("completed-state cap");
  completed.insert(s);
 }
 public:
 explicit Solver(const Dictionary&d):dict(d){}
 Result solve(const Code&first,const Code&second,int d,const Limits&lim=Limits{}){
  if(d!=2&&d!=3)throw std::runtime_error("distance must be2 or3");
  distance=d;limits=lim;result={};models.clear();completed.clear();
  std::array<std::array<int,3>,66> words;for(int i=0;i<33;++i){words[i]=digits(first[i]);words[33+i]=digits(second[i]);}
  try{
   if(std::chrono::steady_clock::now()>limits.deadline)throw Bounded("deadline");
   std::array<std::vector<int>,132> implications;
   if(d==2)for(int i=0;i<33;++i)for(int j=0;j<33;++j)if(confusable(words[i],words[33+j])){implications[2*(33+j)+1].push_back(2*i+1);implications[2*i].push_back(2*(33+j));}
   for(int lit=0;lit<132;++lit){State s{};bool ok=true;std::vector<int> queue{lit};
    while(!queue.empty()){int a=queue.back();queue.pop_back();Bits bit=Bits(1)<<(a/2);bool on=a&1;
     if(s.mask&bit){if(bool(s.on&bit)!=on){ok=false;break;}continue;}
     s.mask|=bit;if(on)s.on|=bit;queue.insert(queue.end(),implications[a].begin(),implications[a].end());}
    closures[lit]=s;closure_ok[lit]=ok;
   }
   std::array<StateSet,3> joined;
   for(int axis=0;axis<3;++axis){std::array<StateSet,7> options;std::array<int,2> inner{};int at=0;for(int k=0;k<3;++k)if(k!=axis)inner[at++]=k;
    for(int t=0;t<7;++t){Pair key{};Bits mask=0;std::array<std::array<int,49>,2> index;for(auto&r:index)r.fill(-1);
     for(int i=0;i<66;++i)if(words[i][axis]==t||words[i][axis]==(t+1)%7){int p=7*words[i][inner[0]]+words[i][inner[1]],h=i/33;if(index[h][p]>=0)throw std::runtime_error("projection collision");index[h][p]=i;key[h]|=U(1)<<p;mask|=Bits(1)<<i;}
     auto found=dict[d].find(key);if(found==dict[d].end())continue;
     for(const auto&p:found->second){Bits on=0;for(int h=0;h<2;++h)for(U m=p[h];m;m&=m-1){int bit=__builtin_ctzll(m);if(index[h][bit]<0)throw std::runtime_error("pattern outside key");on|=Bits(1)<<index[h][bit];}State closed;if(close({mask,on},closed))options[t].insert(closed);}
    }
    for(int i=0;i<7;++i)for(int j=i+1;j<7;++j)for(const State&a:options[i])for(const State&b:options[j]){tick();State s;if(join(a,b,s)&&possible(s)){joined[axis].insert(s);if(joined[axis].size()>limits.joined)throw Bounded("axis joined-state cap");}}
    result.joined[axis]=joined[axis].size();
   }
   result.order={0,1,2};std::stable_sort(result.order.begin(),result.order.end(),[&](int a,int b){return joined[a].size()<joined[b].size();});
   StateSet states=std::move(joined[result.order[0]]);result.successive.push_back(states.size());
   for(int k=1;k<3;++k){StateSet next;for(const State&a:states)for(const State&b:joined[result.order[k]]){tick();State s;if(join(a,b,s)&&possible(s)){next.insert(s);if(next.size()>limits.joined)throw Bounded("cross-axis joined-state cap");}}states=std::move(next);result.successive.push_back(states.size());if(states.empty())break;}
   for(const State&s:states)fill(s);
   result.complete=true;
  }catch(const Bounded&e){result.reason=e.what();}
  result.models.assign(models.begin(),models.end());std::sort(result.models.begin(),result.models.end());return result;
 }
};
} // namespace partition113
