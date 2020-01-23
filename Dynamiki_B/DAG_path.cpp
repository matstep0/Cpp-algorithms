//najdluzsza sicezka w grafie skierowanym
//zadanie upgrade B5
#include<bits/stdc++.h>
using namespace std;
const int roz=500005;
vector<int>  T[roz];  //tablica sasiadow
vector<int>  G[roz]; //graf odwrocony
int L[roz];  //najdluzsza sciezka koncza sie w k
int R[roz]; //najdluzsza sciezka zaczynajaca sie w k
vector<int> top;//kolejnosc topologiczna
bool odw[roz];

void clean(int n){
    for(int i=0;i<=n;i++)
    {
        T[i]=vector<int> ();
        G[i]=vector<int> ();
        L[i]=0;
        R[i]=0;
        top=vector<int> ();
        odw[i]=0;
    }
}
void dfs(int x){
odw[x]=true;
    for(int i=0;i<T[x].size();i++){
        int wie=T[x][i];
        if(odw[wie])continue;

        dfs(wie);

    }
top.push_back(x);
}

int main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
int n,m;
cin>>n>>m;

for(int i=0;i<m;i++){
int a,b;
cin>>a>>b;
T[a].push_back(b);
G[b].push_back(a);
}

for(int i=1;i<=n;i++)
if(!odw[i])dfs(i);


// mam odwrocona topologiczna kolejnosc czyli od najglebszego
/*
for(int i=0;i<top.size();i++)
cout<<top[i]<<" ";
cout<<endl;
*/
R[top[0]]=1;

for(int i=1;i<top.size();i++){
int wie=top[i];
    int M=0;//max
    for(int j=0;j<T[wie].size();j++){   //zeby sprawdzic co wchodzi do wie
        int y=T[wie][j];
        M=max(M,R[y]);
    }
    R[wie]=M+1;
    //cout<<"R["<<wie<<"] "<<R[wie]<<endl;
}


reverse(top.begin(),top.end());//zeby byla topologiczna
/*
for(int i=0;i<top.size();i++)
cout<<top[i]<<" ";
cout<<endl;
*/
L[top[0]]=1;

for(int i=1;i<top.size();i++){
int wie=top[i];
    int M=0;//max
    for(int j=0;j<G[wie].size();j++){   //zeby sprawdzic co wchodzi do wie
        int y=G[wie][j];
        M=max(M,L[y]);
    }
    L[wie]=M+1;
    //cout<<"L["<<wie<<"] "<<L[wie]<<endl;
}

for(int i=1;i<=n;i++){
cout<<L[i]+R[i]-1<<" ";
}
cout<<endl;

clean(n);
}
return 0;
}
