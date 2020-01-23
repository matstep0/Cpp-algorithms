#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second
const int roz=2*1e6+3;
typedef pair<int,int> PA;
PA tree[(int)(1<<22)]; //max dodane
void dodaj(int a,int b,int p,int q,int node ,int co){
if(p==a and b==q){tree[node].nd+=co;tree[node].st+=co ;return;}

int s=(p+q)/2;
if(a<=s)dodaj(a,min(b,s),p,s,2*node,co);
if(b>s) dodaj(max(a,s+1),b,s+1,q,node*2+1,co);
tree[node].st=max(tree[2*node].st,tree[2*node+1].st)+tree[node].nd;
return;
};


struct event{
    int x;
    bool zam; //true oznacza ze to zamkniecie
    pair<int,int> range;
};
vector<pair<PA,PA> > prostokaty ;
vector<event> wydarz ;
bool comp(event a,event b){
    if(a.x<b.x)return true;
    if(a.x>b.x)return false;
    if(a.x==b.x)return a.zam<b.zam;
}
int main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
int n; cin>>n;

set<int> scale;
for(int i=0;i<n;i++){
    int xd,yd,xu,yu;
    cin>>xd>>yd>>xu>>yu;
    prostokaty.push_back(make_pair(PA(xd,yd),PA(xu,yu)));
    scale.insert(yd);
    scale.insert(yu);
};
int ren=0;
int N=1;while(N<scale.size())N*=2;
map<int,int> renum;
for(auto it=scale.begin();it!=scale.end();it++)renum[(*it)]=ren++;
for(auto it=prostokaty.begin();it!=prostokaty.end();it++){
    event o;
    o.x=(*it).st.st;
    o.zam=false;
    o.range=make_pair(renum[(*it).st.nd], renum[(*it).nd.nd]);
    event z;
    z.x=(*it).nd.st;
    z.zam=true;
    z.range=o.range;
    wydarz.push_back(o);
    wydarz.push_back(z);
};
sort(wydarz.begin(),wydarz.end(),comp);
int M=0;
for(auto it=wydarz.begin();it!=wydarz.end();it++){
    int co=((*it).zam)?-1:1;
   // cout<<"co"<<co<<endl;
    int a=(*it).range.st;
    int b=(*it).range.nd;
  //  cout<<a<<" "<<b<<endl;;
    dodaj(a+N,b+N,0,2*N-1,1,co);
    M=max(M,tree[1].st);
   // cout<<M<<endl;
}
cout<<M<<endl;
prostokaty.resize(0);
wydarz.resize(0);
}
return 0;

}
