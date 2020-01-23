/*insert kk ee – wstaw element ee (0≤e≤1090≤e≤109) do kolejki kk
move ss tt – przenieś zawartość kolejki ss do kolejki tt (nie rób nic jeśli s=ts=t)
delmin kk – usuń najmniejszy element z kolejki kk (nie rób nic jeśli jest pusta)
getmin kk – wypisz najmniejszy element w kokejce kk lub -1 jeśli jest pusta
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue< int,vector<int> , greater<int> > T[1000+3];

void ins(int k,int e){
    T[k].push(e);
    return;
};
void mov(int s,int t){ //laczy tak zeby dorzucac mniejsza do wieskzej
    if(s==t)return;
    //if(T[s].size()>T[t].size())swap(T[s],T[t]);
    while(!T[s].empty()){
        T[t].push(T[s].top());
        T[s].pop();
    };
return;
}
void del(int k){
    if(!T[k].empty())T[k].pop();
    return;
}
void getmin(int k){
    if(T[k].empty())cout<<-1;
    else cout<<T[k].top();
    cout<<" ";
    return;
}
int main(){
ios_base::sync_with_stdio(false);
int z;
cin>>z;
while(z--){
int n,m;
cin>>n>>m;
string a;
for(int i=0;i<m;i++){
cin>>a;
if(a=="insert"){
    int k,e; cin>>k>>e;
    ins(k,e);
}else if(a=="move"){
    int s,t; cin>>s>>t;
    mov(s,t);
}else if(a=="delmin"){
    int k; cin>>k;
    del(k);
}else if(a=="getmin"){
    int k; cin>>k;
    getmin(k);
};
}

for(int i=0;i<=n;i++)T[i]=priority_queue< int,vector<int> , greater<int> > ();
cout<<"\n";


}
return 0;
}
