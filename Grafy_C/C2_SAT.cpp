#include<bits/stdc++.h>
using namespace std;
vector<int> T[200004]; //niech 2n onzacza zmienna  2n+1 jej negacje
vector<int> G[200004];
vector<int> topsort;
bool odw[200004];
int color[200004];
bool odwskl[200004];//czy odwiedzilem ta skladowa
int var[200004];//-1 nie bylo

void clean(int n){
    for(int i=0;i<2*n+2;i++){
        topsort=G[i]=T[i]=vector<int> ();
        odw[i]=0;
        color[i]=0;
        odwskl[i]=0;
        var[i]=-1;

    }
}

void dfs(int x){
odw[x]=true;
for(int i=0;i<T[x].size();i++){
if(!odw[ T[x][i] ])dfs(T[x][i]);
}
topsort.push_back(x);
return;
};

void Cdfs(int x,int col){
color[x]=col;
for(int i=0;i<G[x].size();i++){
    if(color[G[x][i]]==0)
    Cdfs(G[x][i],col);
}
return;
}

void malaruj(){
reverse(topsort.begin(),topsort.end());
int colwar=1;
    for(int i=0;i<topsort.size();i++){
        int y=topsort[i];
        if(color[y]==0){
            Cdfs(y,colwar);
            colwar++;
        }
    }
}





int id(int l){ //zwraca index dla liczby
if(l>0)return 2*l-1; //prawda //nieparzyste prawda
else return 2*abs(l);  //negacja //negacja parzyste
}
int main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
    int n; //liczba zmiennych
    int m; // liczba warunkow
    cin>>n>>m;
    clean(n);
        for(int i=0;i<m;i++){
            int x1,x2;
            cin>>x1>>x2;
            T[id(-x1)].push_back(id(x2) );
            T[id(-x2)].push_back(id(x1) );
            //
            G[id(x2)].push_back(id(-x1));
            G[id(x1)].push_back(id(-x2));
        }
//jest graf
    for(int i=1;i<=2*n;i++){
    if(!odw[i])dfs(i);
    }
    malaruj();
    bool er=0;
    for(int i=1;i<=n;i++){
        if(color[id(i)]==color[id(-i)])
        er=1;
    }
if(er)cout<<"NIE"<<endl;
else{
cout<<"TAK"<<endl;

vector<int> S; //wektor na reprezentantow skladowych
    for(int i=0;i<topsort.size();i++){
        int wie=topsort[i];
       int c=color[wie];
       if(!odwskl[c]){S.push_back(wie);odwskl[c]=true;};
    }
    reverse(S.begin(),S.end());
    for(int i=0;i<S.size();i++){
        int nrskl=color[S[i]];
        if(var[nrskl]==-1)
        {
            var[nrskl]=1;
            var[ color[ (S[i]%2==1)?S[i]+1:S[i]-1 ] ]=0;
        }
    }
//wypisujemy
for(int i=1;i<=n;i++){
    cout<<var[color[2*i-1]]<<" ";
}
    cout<<endl;


}


}

return 0;
}
