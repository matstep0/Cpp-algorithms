#include<bits/stdc++.h>
using namespace std;
const int roz=200000+4;
vector<int> T[roz]; //standarody graf
int num[roz]; //numer sciezki na ktorej lezy x
int poz[roz]; //pozycja na sciezce
int ojciec[roz]; //ojciec x
int waga[roz]; //waga dziecka
int pie_na_s[roz]; //pierwszy  na sciezce
set<int> path[roz]; //set z pozycjami zablokowanymi na sciezce //sciezki w drzewie ida z dolu n na gore 1
int nowy_numer_sciezki=0;
bool odw[roz];

void split(int x,int numer, int pozycja){ //heavy light composition //numer sciezki pozycja na sciezce
   odw[x]=true;
   poz[x]=pozycja;
   if(pozycja==0)pie_na_s[numer]=x;
   num[x]=numer;
   int najciezsze=0;
   for(int i=0;i<T[x].size();i++)if(!odw[T[x][i]] and waga[T[x][i]]>waga[najciezsze])najciezsze=T[x][i];
   if(najciezsze>0)split(najciezsze,numer,pozycja+1);
   for(int y:T[x]){
        if(odw[y])continue;
        nowy_numer_sciezki++;
        split(y,nowy_numer_sciezki,0);
   };
    return;
}
///LCA
vector<int> post_pre_order;
vector<int> LCA_tree; //w zerowym wierzcholku bede trzymal rozmiar drzewa
int renum[roz]; //zwraca numer wierzcholka po jego kolejny
int pierwsze_wyst[roz]; //pierwsze wystapienie wierzcholak x
int kolejny=0;
void stworz_drzewo(){ //drzewo minimum
int N=1; //rozmiar dzrzewa
while(N<post_pre_order.size())N*=2;
LCA_tree.resize(2*N+3);
LCA_tree.insert(LCA_tree.begin()+N,post_pre_order.begin(),post_pre_order.end());
for(int a=N-1;a>0;a--)LCA_tree[a]=min(LCA_tree[2*a],LCA_tree[2*a+1]);
LCA_tree[0]=N;
return;
}
int getmin(int a,int b){ //a i b pozycje liczac od 0
 a+=LCA_tree[0];
 b+=LCA_tree[0];
 if(a>b)swap(a,b);
int ret=1e9;
while(true){
    if(a%2==1){ret=min(ret,LCA_tree[a]);a++;}
    if(b%2==0){ret=min(ret,LCA_tree[b]);b--;}
    if(a>b)break;
    a/=2;
    b/=2;
};
return ret;
}
int dfs_waga(int x){ //pisze wage ,ustawia ojca, post_preorder
    odw[x]=true;
    int waga_moja=1;
    renum[kolejny]=x;
     int moj_kolejny=kolejny;
     kolejny++;
    post_pre_order.push_back(moj_kolejny);
    pierwsze_wyst[x]=post_pre_order.size()-1;

    for(int y:T[x]){
        if(odw[y])continue;
        ojciec[y]=x;
        waga_moja+=dfs_waga(y);
        post_pre_order.push_back(moj_kolejny);
    };
    waga[x]=waga_moja;
    return waga_moja;
}
int LCA(int a, int b){ //zwraca wierzchole bedacy LCA
    int m=getmin(pierwsze_wyst[a],pierwsze_wyst[b]);
    return renum[m];
};
///LCA
void dod_us(char z,int x){ //dodaje usuwa skrzyzowanie
    int num_sciez=num[x];
    if(z=='-')path[num_sciez].insert(poz[x]);
    else path[num_sciez].erase(poz[x]);
    return;
}
bool walk(int x,int p,int log=1){ //czy da sie dojsc z punktu a do p przodka
    int S=num[x]; //numer sciezki x
    if(S==num[p]){
      //  cout<<log<<endl;
        auto it_down=path[S].lower_bound(poz[p]);
        if(it_down==path[S].end() or (*it_down)>poz[x])return true;
        else return false;
    };
    auto it_down=path[S].lower_bound(0);
    if(it_down==path[S].end() or (*it_down)>poz[x] )return walk(ojciec[pie_na_s[S]],p,log+1);
    else {return false;}
}
int main(){
int Z; scanf("%i",&Z);
while(Z--){
int n; cin>>n;
for(int i=0;i<n-1;i++){
    int a,b;scanf("%i %i",&a,&b);
    T[a].push_back(b);
    T[b].push_back(a);
};
dfs_waga(1);
fill(odw,odw+n+2,false);
stworz_drzewo();///LCA
split(1,nowy_numer_sciezki,0);
int q;cin>>q;
for(int i=0;i<q;i++){
    char z; cin>>z;
    if(z=='+' or z=='-'){
        int d;scanf("%i",&d);
        dod_us(z,d);
    }else{
        int a,b;
       scanf("%i %i",&a,&b);
        int L=LCA(a,b);
        if(walk(a,L) and walk(b,L))printf("TAK\n");
        else printf("NIE\n");
    };
};
fill(T,T+n+2,vector<int> ());
//fill(num,num+n+2,0);
//fill(poz,poz+n+2,0);
//fill(ojciec,ojciec+n+2,0);
//fill(waga,waga+n+2,0);
//fill(pie_na_s,pie_na_s+n+2,0);
fill(path,path+n+2,set<int> ());
nowy_numer_sciezki=0;
fill( odw,odw+n+2,0);
post_pre_order.resize(0);
LCA_tree.resize(0); //w zerowym wierzcholku bede trzymal rozmiar drzewa
//fill(renum,renum+n+2,0);
//fill(pierwsze_wyst,pierwsze_wyst+n+2,0);
kolejny=0;

}
return 0;
}
