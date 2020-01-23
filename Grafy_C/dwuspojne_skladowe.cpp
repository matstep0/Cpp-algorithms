#include<bits/stdc++.h>
using namespace std;
const int roz=200005;
const int nies=1000000;
vector<int> T[roz];
int kolor[roz]; //0 biały 1 szary 2 czarny
int ojciec[roz];
bool jest[roz];
int lmost[roz];//iczba mostow wychodzacych z x
int odlZ[roz];//nies
int odlP[roz];
int ruz[roz];
bool odw[roz];
#define bialy 0
#define szary 1
#define czarny 2
void BFS(int x,int odl[]){ //odleglosc dfsem bo drzewo
    queue<int> kolejka;
    kolejka.push(x);
    odl[x]=0;
    while(!kolejka.empty()){
        int wie=kolejka.front();
        kolejka.pop();
        odw[wie]=true;
        for(int y:T[wie]){
        //cout<<y<<endl;
            if(!odw[y]){
                odw[y]=true;
                odl[y]=odl[wie]+1;
                kolejka.push(y);
            }
        }
    }

return;
}

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
        odlP[i]=nies;
        odlZ[i]=nies;
        ruz[i]=0;
        odw[i]=0;
        lmost[i]=0;
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
       // if(low[wie]>=numer[wie] and T[wie].size()>1 and !jest[wie]){art.push_back(wie);jest[wie]=true;};//pkt artykulacji wie
        //if(low[wie]>=numer[x] and T[x].size()>1 and x!=1 and !jest[x]){art.push_back(x);jest[x]=true;}
        if(low[wie]==numer[wie]){lmost[wie]++;lmost[x]++;};
        }
    else{if(wie!=ojciec[x])low[x]=min(low[x],numer[wie]); };
}
if(x==1 and liczdfs>1)art.push_back(1);


}
int main(){
 int Z;
 cin>>Z;
while(Z--){
    int n,m,Z,P;
    cin>>n>>m>>Z>>P;
    clean(n);
    for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    T[a].push_back(b);
    T[b].push_back(a);
    }
dfs(1);
BFS(Z,odlZ);
for(int i=0;i<=n;i++)
odw[i]=false;
BFS(P,odlP);
int Mdos=0;//dostepne
int Mndos=0;//niedostepne
    for(int i=1;i<=n;i++){
        ruz[i]=odlP[i]-odlZ[i];//ile dajej ma policjant
        if(T[i].size()-lmost[i]>0)Mdos=max(Mdos,ruz[i]);
        else{Mndos=max(Mndos,odlP[i]);};
    }
if(Mdos>0){cout<<"NIE"<<endl;}
else{cout<<Mndos<<endl;};


}


return 0;
}
