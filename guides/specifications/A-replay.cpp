// Fresh formula reconstruction plus independently audited RUP core.
#define main retained_rup_main
#include "rup_batch.cpp"
#undef main
#define main retained_middle_main
#include "native_middle.cpp"
#undef main
#include "joint_encoder.hpp"
using joint_native::Domain;
static void require(bool b,const string&s){if(!b)throw runtime_error(s);}
static void band(vector<int>const& v){require(v.size()==33&&is_sorted(v.begin(),v.end())&&adjacent_find(v.begin(),v.end())==v.end(),"band shape");for(int w:v)require(w>=0&&w<343,"band range");for(size_t i=0;i<v.size();i++)for(size_t j=0;j<i;j++)require(!joint_native::adjacent(v[i],v[j]),"band independence");}
int main(int argc,char**argv){try{
 ios::sync_with_stdio(false);cin.tie(nullptr);
 require(argc==6,"roots middle-patterns joint-patterns templates mode");auto mode=joint_native::parse_mode(argv[5]);auto started=Clock::now();
 map<int,vector<int>> roots;{ifstream in(argv[1]);require(bool(in),"root file");string s;while(getline(in,s)){auto t=tokens(s);require(t.size()==34,"root fields");int r=integer(t[0]);require(r>=0&&r<1016,"root ID");vector<int>v;for(size_t i=1;i<t.size();i++)v.push_back(integer(t[i]));band(v);require(roots.emplace(r,v).second,"duplicate root");}require(in.eof()&&!roots.empty(),"root read");}
 map<int,Dict> middle;{ifstream in(argv[2]);require(bool(in),"middle pattern file");string s;while(getline(in,s)){istringstream row(s);int r;U a,b,m;string extra;require(bool(row>>r>>a>>b>>m)&&!(row>>extra),"middle pattern fields");require(roots.count(r)&&!(a>>49)&&!(b>>49)&&!(m>>49),"middle pattern domain");middle[r][{a,b}].push_back(m);}require(in.eof(),"middle pattern read");}
 for(auto&[r,d]:middle)for(auto&[k,v]:d){sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());}
 map<int,Domain> joint;{ifstream in(argv[3]);require(bool(in),"joint pattern file");string s;while(getline(in,s)){istringstream row(s);int r;U a,b,m,y;string extra;require(bool(row>>r>>a>>b>>m>>y)&&!(row>>extra),"joint pattern fields");require(roots.count(r)&&!(a>>49)&&!(b>>49)&&!(m>>49)&&!(y>>49),"joint pattern domain");joint[r][{a,b}].push_back({m,y});}require(in.eof(),"joint pattern read");}
 map<int,Template> ts;{ifstream in(argv[4]);require(bool(in),"template file");int n,a,c;while(in>>ws && in.peek()!=EOF){require(bool(in>>n>>a>>c),"truncated template header");require(n>=16&&n<=30&&a>=0&&c>=0&&a<1000000,"template header");Template t{a,{}};for(int k=0;k<c;k++){vector<int>cl;int v;while(in>>v&&v){require(v>=-(n+a)&&v<=n+a,"template literal");cl.push_back(v);}require(bool(in),"template clause");t.clauses.push_back(move(cl));}require(ts.emplace(n,move(t)).second,"duplicate template");}require(in.eof()&&ts.size()==15,"template coverage");}
 uint64_t cases=0,verified=0,formula_only=0;bool finished=false;string first;
 while(getline(cin,first)){
  auto t=tokens(first);if(t.size()==2&&t[0]=="DONE"){require(integer(t[1])>=0&&uint64_t(integer(t[1]))==cases,"DONE count");finished=true;break;}
  require(t.size()==10&&t[0]=="CASE","case header");int id=integer(t[1]),root=integer(t[2]),global=integer(t[3]),local=integer(t[4]);string role=t[5],digest=t[8],status=t[9];int expected_nv=integer(t[6]),expected_nc=integer(t[7]);require(id>=0&&uint64_t(id)==cases&&roots.count(root)&&global>=0&&local>=0,"case identity");require(role=="M"||role=="J"||role=="E","case role");require(status=="UNSAT"||status=="FORMULA","case expectation");require(role!="E"||status=="UNSAT","exhaustion requires UNSAT");require(digest.size()==64&&all_of(digest.begin(),digest.end(),[](char c){return(c>='0'&&c<='9')||(c>='a'&&c<='f');}),"digest syntax");
  auto wt=tokens(line());require(wt.size()==34&&wt[0]=="WORDS","case words");vector<int>second;for(size_t k=1;k<wt.size();k++)second.push_back(integer(wt[k]));band(second);
  CNF cnf;int nv=0,physical=0;
  if(role=="M"){auto result=build(roots.at(root),second,middle.at(root),ts);cnf=move(result.first);nv=result.second;}
  else{auto result=joint_native::encode(roots.at(root),second,joint.at(root),mode);nv=result.variables;for(int v:result.X)physical+=v!=0;for(int v:result.Y)physical+=v!=0;cnf=move(result.clauses);}
  auto bh=tokens(line());require(bh.size()==2&&bh[0]=="BLOCKS","block header");int nb=integer(bh[1]);require(nb>=0&&(role=="E"||nb==0),"block role/count");
  for(int b=0;b<nb;b++){auto cl=clause(tokens(line()),0,nv);require(int(cl.size())==physical,"physical block size");vector<int>vars;for(int x:cl)vars.push_back(abs(x));sort(vars.begin(),vars.end());for(int k=0;k<physical;k++)require(vars[k]==k+1,"block includes every physical variable exactly once");cnf.push_back(move(cl));}
  require(nv>0&&nv<=10000000&&cnf.size()<=10000000,"generated formula size guard");require(nv==expected_nv&&int(cnf.size())==expected_nc,"formula size mismatch");require(sha(text(cnf,nv))==digest,"regenerated formula SHA mismatch");
  auto ph=tokens(line());require(ph.size()==2&&ph[0]=="PROOF","proof header");int np=integer(ph[1]);require(np>=0&&(status!="FORMULA"||np==0),"proof count");uint64_t adds=0;bool empty=false;
  Checker check(nv);if(status=="UNSAT")for(auto const&cl:cnf){for(int v:cl)require(v!=0&&v>=-nv&&v<=nv,"generated literal");check.add(cl);}
  for(int k=0;k<np;k++){auto pt=tokens(line());require(!pt.empty()&&pt[0]!="d","additions-only proof required");auto cl=clause(pt,0,nv);require(!empty,"addition after empty");require(check.rup(cl),"non-RUP addition case"+to_string(id));empty=cl.empty();check.add(move(cl));++adds;}
  require(status=="FORMULA"||empty,"missing verified empty");require(line()=="END","case END");if(status=="UNSAT")++verified;else ++formula_only;
  cout<<"{\"case_id\":"<<id<<",\"root\":"<<root<<",\"global_pair_index\":"<<global<<",\"local_pair_index\":"<<local<<",\"role\":\""<<role<<"\",\"status\":\""<<(status=="UNSAT"?"VERIFIED_RUP":"VERIFIED_FORMULA")<<"\",\"cnf_sha256\":\""<<digest<<"\",\"additions\":"<<adds<<",\"propagations\":"<<check.propagations<<"}\n";++cases;
 }
 require(finished,"missing DONE");require(cases>0,"empty replay");require(!getline(cin,first)&&cin.eof(),"trailing input");cout.flush();require(bool(cout),"result write");cerr<<"VERIFIED_NATIVE_REPLAY cases="<<cases<<" RUP="<<verified<<" formula_only="<<formula_only<<" seconds="<<elapsed(started)<<"\n";return 0;
}catch(exception const&e){cerr<<"REJECT: "<<e.what()<<"\n";return 1;}}
