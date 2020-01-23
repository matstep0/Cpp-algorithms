//C6
#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second
const int roz=2*2098000;
const int nies=roz-1;
bool odw[roz];
vector<int> T[roz];
int drzewo[6*roz]; //trzynmam numery do porownania nalezy uzyc numer[y]
pair<int,int> zakres[roz];
int it;
int numer[roz]; //nies
int nadaj=0;
int pierwsze[roz];
int czysto(int N){
    for(int i=0;i<=N+1;i++){
        odw[i]=false;
        T[i]=vector<int>();
        drzewo[i]=0;
        zakres[i]=pair<int,int>(0,0);
        numer[i]=nies;
        nadaj=0;
        pierwsze[i]=0;
    }

}
void dfs(int x){
odw[x]=true;
pierwsze[x]=it;
drzewo[it]=x;
numer[x]=nadaj;
nadaj++;
it--;
    for(int y:T[x]){
        if(!odw[y]){
            dfs(y);
            drzewo[it]=x;
            it--;
        }
    }


}

void wyp_drzewo(int N){
    while(it>=N){
        drzewo[it]=nies;
        it--;
    }
    while(it>0){
       if(numer[drzewo[2*it] ]<numer[drzewo[2*it+1] ] )
       drzewo[it]=drzewo[2*it];
       else
       drzewo[it]=drzewo[2*it+1];
       it--;
    }
    int wsk=2*N-1;

    while(wsk>=N){
        zakres[wsk]=pair<int,int>(wsk,wsk);
        wsk--;
    }
    while(wsk>0){
        zakres[wsk]=pair<int,int>(zakres[2*wsk].first,zakres[2*wsk+1].second);
        wsk--;
    }
};
int minimum(int a,int b,int x){ //zwraca wierzcholek ktorego numer jest najmniejszy
    if(zakres[x].first==a and zakres[x].second==b)return drzewo[x];

    int w1=nies,w2=nies;
    if(a<=zakres[2*x].nd)w1=minimum(a,min(b,zakres[2*x].nd),2*x);
    if(b>=zakres[2*x+1].st)w2=minimum(max(a,zakres[2*x+1].st),b,2*x+1);
    if(numer[w1]<numer[w2])return w1;
    else
    return w2;

}
int main(){
ios_base::sync_with_stdio(false);
numer[nies]=nies;
int Z;
cin>>Z;
while(Z--){
    int n;
    cin>>n;
    int N=1;
    while(N<2*n)N*=2;
    czysto(N);
    it=2*N-1;
        for(int i=1;i<=n-1;i++){
            int nr;
            cin>>nr;
            //i ta rzeka wpada nr krawedz nr->i
            T[nr].push_back(i);
        }
    dfs(0);
    wyp_drzewo(N);
    int m;
    cin>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        if(pierwsze[a]>pierwsze[b])swap(a,b);
        cout<<minimum(pierwsze[a],pierwsze[b],1)<<endl;
    }

}


return 0;
}
