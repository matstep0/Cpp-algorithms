#include<bits/stdc++.h>
using namespace std;
const int roz=200000+4;
vector<int> T[roz]; //standarody graf
bool niemoge[roz];
bool odw[roz];
bool dfs(int x,int cel){
odw[x]=true;
if(niemoge[x])return false;
if(x==cel)return true;
for(int y:T[x]){
    if(odw[y])continue;
    if(dfs(y,cel))return true;
}
return false;
};

int main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
int n; cin>>n;
for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;
    T[a].push_back(b);
    T[b].push_back(a);
};

int q;cin>>q;
for(int i=0;i<q;i++){
    char z; cin>>z;
    if(z=='+'){int d; cin>>d;niemoge[d]=0;}
    if(z=='-'){int d;cin>>d;niemoge[d]=1;}
    if(z=='?'){ int a,b;
        cin>>a>>b;
       if(dfs(a,b))cout<<"TAK"<<endl;
       else cout<<"NIE"<<endl;
       fill(odw,odw+n+1,false);
    };
}

fill(odw,odw+n+1,false);
fill(niemoge,niemoge+n+1,false);

}
return 0;
}
