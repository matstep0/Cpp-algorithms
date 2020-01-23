#include<bits/stdc++.h>
using namespace std;
const int roz=200005;
vector<int> T[roz];
int kolor[roz]; //0 biały 1 szary 2 czarny
int ojciec[roz];
bool jest[roz];
#define bialy 0
#define szary 1
#define czarny 2

int numer[roz]; //numer wierzchlka tak zeby korzenie byly nizsze
int nadaj=1;
int low[roz];//najnizszy wskazuje na wierzcholek o najnizszym numerze do ktorego prowadzi krawedz wsteczna
vector<int> art;
vector<pair<int,int>>most;
void clean(int n){
    for(int i=0;i<=n;i++){
        T[i]=vector<int> ();
        kolor[i]=bialy;
        ojciec[i]=0;
        numer[i]=0;
        low[i]=0;
        jest[i]=0;
    }
    nadaj=0;
    art.resize(0);
    most.resize(0);
    return;
}
void dfs(int x){
int liczdfs=0;
    numer[x]=nadaj;
    nadaj++;
    low[x]=numer[x];
    kolor[x]=szary;
for(int i=0;i<T[x].size();i++){
    int wie=T[x][i];
    if(kolor[wie]==bialy){
        ojciec[wie]=x;
        dfs(wie);liczdfs++;
        low[x]=min(low[wie],low[x]);
        if(low[wie]>=numer[wie] and T[wie].size()>1 and !jest[wie]){art.push_back(wie);jest[wie]=true;};//pkt artykulacji wie
        if(low[wie]>=numer[x] and T[x].size()>1 and x!=1 and !jest[x]){art.push_back(x);jest[x]=true;}
        if(low[wie]==numer[wie])most.push_back(pair<int,int>(min(x,wie),max(x,wie)));//most wie->x
    }
    else{if(wie!=ojciec[x])low[x]=min(low[x],numer[wie]); };
}
if(x==1 and liczdfs>1)art.push_back(1);


}
int main(){
 int Z;
 cin>>Z;
while(Z--){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    T[a].push_back(b);
    T[b].push_back(a);
    }
dfs(1);
sort(art.begin(),art.end());
sort(most.begin(),most.end());
for(int i=0;i<art.size();i++){
cout<<art[i]<<endl;
}
for(int i=0;i<most.size();i++){
cout<<most[i].first<<" "<<most[i].second<<endl;
}
clean(n);

}


return 0;
}
