#include<bits/stdc++.h>
using namespace std;
vector<int> T[(int)(2*1e4+5)];
int kumpel[(int)(2*1e4+5)];
bool odw[(int)(2*1e4+5)];
bool dfs(int x);
void turbomatching(int n){
bool stop=1;
    fill(odw,odw+n+1,0);
    for(int i=1;i<=n;i++)
        if(kumpel[i]==0 and odw[i]==false)  //nieskojarzony
         if(dfs(i))stop=0;
};
bool dfs(int x){
odw[x]=true;
    for(int y:T[x]){
        if(odw[y]==true)continue;
        odw[y]=true;
        if(kumpel[y]==0){
            kumpel[y]=x;
            kumpel[x]=y;
            return true;
        }else{
            int z=kumpel[y];
            if(odw[z]==true)continue;
            if(dfs(z)==true){
                kumpel[x]=y;
                kumpel[y]=x;
                return true;
            }
        }
    }
    return false;

}

int main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
int n1,n2,m;
cin>>n1>>n2>>m;
    for(int i=1;i<m;i++){
        int a,b;
        cin>>a>>b;
        T[a].push_back(b+n1);
        T[b+n1].push_back(a);
    }
    turbomatching(n1+n2);
    int wynik=0;
    for(int i=1;i<=n1;i++)
    if(kumpel[i]!=0)wynik++;
    cout<<wynik<<endl;
    for(int i=1;i<=n1+n2;i++){
        T[i]=vector<int> ();
        kumpel[i]=0;
        odw[i]=0;
    }




}



return 0;
}
