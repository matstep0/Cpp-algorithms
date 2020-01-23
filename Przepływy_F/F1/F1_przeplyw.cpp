#include<bits/stdc++.h>
using namespace std;
int c[101][101];//maksymalny przeplyw
int f[101][101];//przeplyw
vector<int> T[101]; //sasiedz
vector<bool> odw;
vector<pair<int,int> > sciezka; //sciezka po ktorej szedl dfs
void clean(int n){
    odw=vector<bool> ();
    for(int i=1;i<=n;i++)
     T[i]=vector<int> ();
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
      f[i][j]=0;
    sciezka=vector<pair<int,int> > ();
};
bool dfs(int x,int cel){
    odw[x]=true;
    if(x==cel)return true;
    for(int y:T[x]){
        if(odw[y]==true)continue;
        if(f[x][y]<c[x][y])
            if(dfs(y,cel)==true){
                sciezka.push_back(make_pair(x,y) );
                return true;
            };
    }
return false;
};

main(){
int Z;
cin>>Z;
while(Z--){
int n;
cin>>n;

for(int i=1;i<=n;i++) //wiersze
 for(int j=1;j<=n;j++){//kolumny
    cin>>c[i][j];
    T[i].push_back(j);
 };

/*
for(int i=1;i<=n;i++)
 for(int j=i+1;j<=n;j++){
    c[i][j]+=c[j][i];
    c[j][i]=c[i][j];
    if(c[i][j]>0){
     T[i].push_back(j);
     T[j].push_back(i);
    }
 };
*/
odw.resize(n+1,0);
 while(dfs(1,n)==true){

    int MIN=1e9;
    for(int i=0;i<sciezka.size();i++){
        MIN=min(MIN,c[sciezka[i].first][sciezka[i].second]-f[sciezka[i].first][sciezka[i].second]);
    };
    for(int i=0;i<sciezka.size();i++){
        int x=sciezka[i].first;
        int y=sciezka[i].second;
        f[x][y]+=MIN;
        f[y][x]-=MIN;
    };
    sciezka= vector<pair<int,int> >();
    odw.assign(n+1,false);
 };
 int suma=0;
 for(int y:T[n]){
    suma+=f[y][n];
 };
 cout<<suma<<endl;
clean(n);

}



return 0;
}
