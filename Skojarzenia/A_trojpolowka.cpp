#include<bits/stdc++.h>
using namespace std;
const int roz=3000+7;
vector<int> T[roz];
int kumpel[roz]; //wypelnij
bool odw[roz];

void clean(int n){
n=2*n+1;
for(int i=1;i<=n;i++){
    T[i]=vector<int> ();
    kumpel[i]=0;
};
fill(odw,odw+n+2,false);

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
 for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    b+=n;
    T[a].push_back(b);
    T[b].push_back(a);
 };

 bool er=1;

 while(er==1){
fill(odw,odw+2*n+1,false);
  er=0;
  for(int i=1;i<=n*2;i++)
    if(odw[i]==false and kumpel[i]<=0)
        if(dfs(i)==true){er=1;}

 };
 int suma=0;
 for(int i=1;i<=n;i++)
    if(kumpel[i]>0)suma++;

if(suma==n)cout<<"TAK"<<endl;
else cout<<"NIE"<<endl;
clean(n);

}


return 0;
}
