#include<bits/stdc++.h>
using namespace std;
vector<int> T[int(2*1e4+5)];
int kumpel[int(2*1e4+5)]; //wypelnij
vector<bool> odw;

void clean(int n){
for(int i=1;i<=n;i++){
    T[i]=vector<int> ();
    kumpel[i]=0;
};
odw=vector<bool> ();

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
 int n1,n2,m;
 cin>>n1>>n2>>m;
 for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    b+=n1;
    T[a].push_back(b);
    T[b].push_back(a);
 };
 odw.resize(n1+n2+1,false);
 bool er=1;
 while(er==1){
 odw.resize(n1+n2+1,false);
  er=0;
  for(int i=1;i<=n1+n2;i++)
    if(odw[i]==false and kumpel[i]<=0)
        if(dfs(i)==true){er=1;continue;}

 };
 int suma=0;
 for(int i=1;i<=n1;i++)
    if(kumpel[i]>0)suma++;
 cout<<suma<<endl;
clean(n1+n2+1);


}


return 0;
}
