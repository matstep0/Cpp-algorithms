//najlepsze pokrycie wierzhcołkowe dla grafu ważonego skierowanego
#include<bits/stdc++.h>
using namespace std;
const int roz=200004;
vector<int> T[roz];
int waga[roz];
int ojciec[roz];
bool odw[roz];
long long N_z_x[roz]; //najlepsze pokrycie wierzcholkowe poddrzewa zawierajace x
long long N_bez_x[roz]; //najlepsze pokrycie wierzcholkowe poddrzewa niezawierajce x
bool wziety[roz];

void clean(int n){
for(int i=0;i<=n;i++){
ojciec[i]=0;
odw[i]=0;
T[i]=vector<int> ();
wziety[i]=false;
}

}

void dfs(int x,int p){
odw[x]=true;

for(int i=0;i<T[x].size();i++){
    if(odw[T[x][i]]==true)continue;
    if(T[x][i]!=ojciec[x]){
    ojciec[T[x][i]]=x;
    dfs(T[x][i],x);
    }
}
return;
}

void oblicz_dfs(int x){  //oblicza dynamicznie najwieksze najlepsze pokrycie wierzcholkowe dla poddrzewa x
if(T[x].size()==1 and x!=ojciec[x]){N_z_x[x]=waga[x];N_bez_x[x]=0;}
N_bez_x[x]=0;
N_z_x[x]=waga[x];
for(int i=0;i<T[x].size();i++){
    int wie=T[x][i];
    if(wie==ojciec[x])continue;
    oblicz_dfs(wie);
    N_bez_x[x]+=N_z_x[wie];
    N_z_x[x]+=min(N_bez_x[wie],N_z_x[wie]);
}
return;
}


void odtworz(int x){
if(wziety[ ojciec[x] ]==false)wziety[x]=true;
else{
    if(N_z_x[x]<N_bez_x[x])
        wziety[x]=true;
    else{
        wziety[x]=false;
    }
};
for(int i=0;i<T[x].size();i++){
int wie= T[x][i];
if(wie==ojciec[x])continue;
odtworz(wie);
}


return;
}



void drzewo(int n){

for(int i=1;i<=n;i++){
    if(!odw[i]){
        ojciec[i]=i;
        dfs(i,i);
    }
}


}
int main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>waga[i];

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        T[a].push_back(b);
        T[b].push_back(a);
    };
//readed
drzewo(n);
int szef;
for(int i=1;i<=n;i++)
if(ojciec[i]==i)szef=i;
oblicz_dfs(szef);
cout<<min(N_bez_x[szef],N_z_x[szef])<<endl;
//
if(N_z_x[szef]<N_bez_x[szef])wziety[szef]=true;
else{
wziety[szef]=false;
}
for(int i=0;i<T[szef].size();i++)
odtworz(T[szef][i]);
//
for(int i=1;i<=n;i++)
cout<<wziety[i];
cout<<endl;
clean(n);
}
return 0;
}
