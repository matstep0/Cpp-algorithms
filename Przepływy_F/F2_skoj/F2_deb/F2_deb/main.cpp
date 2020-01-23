#include<bits/stdc++.h>
using namespace std;
vector<int> T[int(2*1e4+5)];
int kumpel[int(2*1e4+5)]; //wypelnij
bool odw[int(2*1e4+5)];

void clean(int n){
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
 int n1,n2,m;
 cin>>n1>>n2>>m;
 for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    b+=n1;
    T[a].push_back(b);
    T[b].push_back(a);
 };

 bool er=1;

 while(er==1){
fill(odw,odw+n1+n2+1,false);
  er=0;
  for(int i=1;i<=n1+n2;i++)
    if(odw[i]==false and kumpel[i]<=0)
        if(dfs(i)==true){er=1;}

 };
 int suma=0;
 for(int i=1;i<=n1;i++)
    if(kumpel[i]>0)suma++;
 cout<<suma<<endl;
clean(n1+n2+1);


}


return 0;
}
