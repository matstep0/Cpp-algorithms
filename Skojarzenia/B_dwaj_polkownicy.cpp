#include<bits/stdc++.h>
using namespace std;
const int roz=1e5+5;
vector<int> T[roz];
int kumpel[roz]; //wypelnij
bool odw[roz];
string P[100];
int numer[101][101];
bool kolor[roz];
bool ominac[roz];

void clean(int n,int m){
 for(int i=1;i<=n;i++){
    T[i]=vector<int> ();
    kumpel[i]=0;
    odw[i]=false;
    kolor[i]=0;
    ominac[i]=0;
    P[i]="";
 };
 for(int i=1;i<=n;i++)
 for(int j=1;j<=m;j++)
 numer[i][j]=0;
}
bool dfs(int x){
    odw[x]=true;
    for(int y:T[x]){
     if(odw[y]==true)continue;
     if(kumpel[y]<=0){
        odw[y]=true;
        kumpel[x]=y;
        kumpel[y]=x;
        return true;
     }
     else{
        int z=kumpel[y];
        odw[y]=true;
        if(dfs(z)==true){
            kumpel[x]=y;
            kumpel[y]=x;
            return true;
        }

     };
    }
    return false;
};

int main(){
int Z;
cin>>Z;
while(Z--){
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=n;i++){
    string A;
    cin>>A;
    P[i]="P"+A;
 }

int kol=1;
for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
    if(P[i][j]=='X')continue;
    numer[i][j]=kol;
    kol++;
  };
  kol--;

  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
    if(P[i][j]=='X')continue;
      if(i-1>0 and numer[i-1][j]!=0)T[numer[i][j]].push_back(numer[i-1][j]);
      if(i+1<=n and numer[i+1][j]!=0)T[numer[i][j]].push_back(numer[i+1][j]);
      if(j-1>0 and numer[i][j-1]!=0)T[numer[i][j]].push_back(numer[i][j-1]);
      if(j+1<=m and numer[i][j+1]!=0)T[numer[i][j]].push_back(numer[i][j+1]);
      kolor[numer[i][j]]=( (i+j)%2==0 )? 0:1 ;
  };


 bool er=1;

 while(er==1){
fill(odw,odw+kol+2,false);
  er=0;
  for(int i=1;i<=kol;i++)
    if(odw[i]==false and kumpel[i]<=0)
        if(dfs(i)==true){er=1;}
 };
 fill(odw,odw+kol+2,false);
 for(int i=1;i<=kol;i++){
    if(kolor[i]==0){
        if(odw[i]==false and kumpel[i]==0)dfs(i);
    }
 };
 for(int i=1;i<=kol;i++)
  if(odw[i]==true and kolor[i]==0)ominac[i]=true;

fill(odw,odw+kol+2,false);
 for(int i=1;i<=kol;i++){
    if(kolor[i]==1){
        if(odw[i]==false and kumpel[i]==0)dfs(i);
    }
 }
 for(int i=1;i<=kol;i++)
  if(odw[i]==true and kolor[i]==1)ominac[i]=true;

  for(int i=1;i<=n;i++){
     for(int j=1;j<=m;j++){
     if(P[i][j]=='X'){cout<<"X";continue;}
     if(ominac[numer[i][j]])cout<<"K";
     else cout<<"W";
   }
   cout<<endl;
  }
clean(n,m);

}



return 0;
}
