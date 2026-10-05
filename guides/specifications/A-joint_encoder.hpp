#pragma once
// Literal-order port of frozen joint.py, using only standard C++17.
#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdlib>
#include <iterator>
#include <limits>
#include <map>
#include <ostream>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>
namespace joint_native {
using Mask=std::uint64_t;using Clause=std::vector<int>;using CNF=std::vector<Clause>;
using Pattern=std::array<Mask,2>;using Key=std::array<Mask,2>;
using Domain=std::map<Key,std::vector<Pattern>>;
using Tables=std::array<std::array<std::vector<Pattern>,7>,3>;
enum class Mode{all9,restricted17_16};
inline Mode parse_mode(std::string const&s){if(s=="all9")return Mode::all9;if(s=="restricted17-16")return Mode::restricted17_16;throw std::runtime_error("joint mode");}
inline std::array<int,3> coords(int v){if(v<0||v>=343)throw std::runtime_error("joint word range");return{v/49,v/7%7,v%7};}
inline bool adjacent(int a,int b){auto x=coords(a),y=coords(b);for(int k=0;k<3;k++){int d=(x[k]-y[k]+7)%7;if(d!=0&&d!=1&&d!=6)return false;}return true;}
inline std::array<std::vector<int>,343> const& neighbors(){static const auto table=[](){std::array<std::vector<int>,343>a;for(int v=0;v<343;v++)for(int w=0;w<343;w++)if(adjacent(v,w))a[v].push_back(w);return a;}();return table;}
inline int plane_point(std::array<int,3>const&w,int axis){int p=0;for(int k=0;k<3;k++)if(k!=axis)p=7*p+w[k];return p;}
inline Mask project(std::vector<int>const&words,int axis,int t){if(axis<0||axis>=3||t<0||t>=7)throw std::runtime_error("joint projection axis/window");Mask m=0;for(int v:words){auto w=coords(v);if(w[axis]==t||w[axis]==(t+1)%7){Mask bit=Mask(1)<<plane_point(w,axis);if(m&bit)throw std::runtime_error("noninjective word projection");m|=bit;}}return m;}
struct Formula{
 CNF clauses;int top=0;
 int var(){if(top==std::numeric_limits<int>::max())throw std::runtime_error("variable overflow");return ++top;}
 void add(Clause clause){clauses.push_back(std::move(clause));}
 std::vector<int> thresholds(std::vector<int>const&variables,int cap=20){
  if(cap<0)throw std::runtime_error("negative threshold cap");int truth=var();add({truth});std::vector<int>prev(cap+1,-truth);prev[0]=truth;
  for(std::size_t i=0;i<variables.size();i++){int v=variables[i];std::vector<int>next{truth};for(int k=1;k<=cap;k++){if(k>int(i)+1){next.push_back(-truth);continue;}int a=prev[k],b=prev[k-1],z=var();next.push_back(z);add({-a,z});add({-b,-v,z});add({-z,a,b});add({-z,a,v});}prev=std::move(next);}return prev;
 }
};
struct Result{CNF clauses;std::array<int,343>X{},Y{};int variables=0;};
inline void add_cardinality(Formula&F,std::vector<int>const&tx,std::vector<int>const&ty,Mode mode){
 if(tx.size()<21||ty.size()<21)throw std::runtime_error("joint threshold length");
 if(mode==Mode::all9){F.add({tx[16]});F.add({-tx[20]});F.add({ty[15]});F.add({-ty[20]});for(auto ch:std::array<std::array<int,3>,4>{{{16,15,15},{17,16,17},{18,16,18},{19,17,19}}}){int c=ch[0],lo=ch[1],hi=ch[2];F.add({-tx[c],tx[c+1],ty[lo]});F.add({-tx[c],tx[c+1],-ty[hi+1]});}}
 else if(mode==Mode::restricted17_16){F.add({tx[17]});F.add({-tx[18]});F.add({ty[16]});F.add({-ty[17]});}
 else throw std::runtime_error("joint mode enum");
}
inline Result encode_tables(std::vector<int>const&b0_input,std::vector<int>const&b1_input,Tables const&tables,Mode mode){
 std::set<int>b0(b0_input.begin(),b0_input.end()),b1(b1_input.begin(),b1_input.end());for(int v:b0)coords(v);for(int v:b1)coords(v);
 std::vector<int>common,forced;std::set_intersection(b0.begin(),b0.end(),b1.begin(),b1.end(),std::back_inserter(common));std::set_difference(b1.begin(),b1.end(),b0.begin(),b0.end(),std::back_inserter(forced));
 std::array<bool,343>blocked{};for(int w:forced)for(int v:neighbors()[w])blocked[v]=true;std::vector<int>D;for(int v=0;v<343;v++)if(!blocked[v])D.push_back(v);
 Formula F;Result out;for(int v:common)out.X[v]=F.var();for(int v:D)out.Y[v]=F.var();
 for(int v:D){for(int w:common)if(adjacent(v,w))F.add({-out.Y[v],out.X[w]});for(int w:neighbors()[v])if(w>v&&out.Y[w])F.add({-out.Y[v],-out.Y[w]});}
 for(int axis=0;axis<3;axis++){
  std::vector<int>windows;
  for(int t=0;t<7;t++){
   int window=F.var();windows.push_back(window);std::vector<int>selectors;std::array<std::vector<int>,49>lifts;std::vector<std::pair<int,int>>middle_lifts;Mask middle_plane=0;
   for(int v:D){auto w=coords(v);if(w[axis]==t||w[axis]==(t+1)%7)lifts[plane_point(w,axis)].push_back(out.Y[v]);}
   for(int v:common){auto w=coords(v);if(w[axis]==t||w[axis]==(t+1)%7){int p=plane_point(w,axis);if((middle_plane>>p)&1)throw std::runtime_error("noninjective common projection");middle_plane|=Mask(1)<<p;middle_lifts.push_back({p,out.X[v]});}}
   auto patterns=tables[axis][t];std::sort(patterns.begin(),patterns.end());patterns.erase(std::unique(patterns.begin(),patterns.end()),patterns.end());
   for(auto const&pattern:patterns){Mask middle=pattern[0],row3=pattern[1];if((middle>>49)||(row3>>49))throw std::runtime_error("joint pattern mask range");if(middle&~middle_plane)continue;bool allowed=true;for(int p=0;p<49;p++)if(((row3>>p)&1)&&lifts[p].empty()){allowed=false;break;}if(!allowed)continue;
    int selector=F.var();selectors.push_back(selector);F.add({-selector,window});for(auto [p,x]:middle_lifts)F.add({-selector,((middle>>p)&1)?x:-x});
    for(int p=0;p<49;p++){if((row3>>p)&1){Clause clause{-selector};clause.insert(clause.end(),lifts[p].begin(),lifts[p].end());F.add(std::move(clause));for(std::size_t i=0;i<lifts[p].size();i++)for(std::size_t j=i+1;j<lifts[p].size();j++)F.add({-selector,-lifts[p][i],-lifts[p][j]});}else for(int x:lifts[p])F.add({-selector,-x});}
   }
   Clause clause{-window};clause.insert(clause.end(),selectors.begin(),selectors.end());F.add(std::move(clause));
  }
  for(int omitted=0;omitted<7;omitted++){Clause clause;for(int i=0;i<7;i++)if(i!=omitted)clause.push_back(windows[i]);F.add(std::move(clause));}
 }
 std::vector<int>xs,ys;for(int v:common)xs.push_back(out.X[v]);for(int v:D)ys.push_back(out.Y[v]);auto tx=F.thresholds(xs),ty=F.thresholds(ys);
 add_cardinality(F,tx,ty,mode);
 out.variables=F.top;out.clauses=std::move(F.clauses);return out;
}
inline Result encode(std::vector<int>const&b0,std::vector<int>const&b1,Domain const&domain,Mode mode){Tables tables;for(int a=0;a<3;a++)for(int t=0;t<7;t++){auto it=domain.find({project(b0,a,t),project(b1,a,t)});if(it!=domain.end())tables[a][t]=it->second;}return encode_tables(b0,b1,tables,mode);}
inline std::string dimacs(Result const&r){std::string text="p cnf "+std::to_string(r.variables)+" "+std::to_string(r.clauses.size())+"\n";for(auto const&cl:r.clauses){for(int v:cl){text+=std::to_string(v);text+=' ';}if(cl.empty())text+=' ';text+="0\n";}return text;}
inline void write_u32(std::ostream&out,std::uint32_t v){char bytes[4];for(int i=0;i<4;i++)bytes[i]=char((v>>(8*i))&255);out.write(bytes,4);if(!out)throw std::runtime_error("joint binary write");}
inline void write_magic(std::ostream&out){out.write("C7MC",4);if(!out)throw std::runtime_error("joint binary magic write");}
inline void write_record(std::ostream&out,std::array<std::uint32_t,3>ids,Result const&r){for(auto v:ids)write_u32(out,v);if(r.variables<0||r.clauses.size()>std::numeric_limits<std::uint32_t>::max())throw std::runtime_error("joint binary size");write_u32(out,r.variables);write_u32(out,r.clauses.size());for(auto const&cl:r.clauses){if(cl.size()>std::numeric_limits<std::uint32_t>::max())throw std::runtime_error("joint binary clause size");write_u32(out,cl.size());for(int v:cl){if(v==0||std::abs(v)>r.variables)throw std::runtime_error("joint binary literal range");write_u32(out,static_cast<std::uint32_t>(v));}}}
} // namespace joint_native
