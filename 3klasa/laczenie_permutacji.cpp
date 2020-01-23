#include<bits/stdc++.h>
using namespace std;
const int roz=200000+4;
vector<int> tree[ ( (int)(4*roz))];
void czyt(vector<int> a){
for(auto it=a.begin();it!=a.end();it++)cout<<(*it)<<" "; cout<<endl;
return;
}
vector<int> lacz(vector<int> a,vector<int> b){ //laczy permutacje
    vector<int> ret(9);
    for(int x=1;x<=8;x++)ret[x]=a[b[x]];
    return ret;

}
void tworz(int N){
for(int i=N-1;i>0;i--)tree[i]=lacz(tree[i*2],tree[i*2+1]);
};
void update(int x,vector<int> U,int N){
    x+=N-1;
    tree[x]=U;
    x/=2;
    while(x>0){
        tree[x]=lacz(tree[x*2],tree[x*2+1]);
        x/=2;
    };
return;

}
int main(){
ios_base::sync_with_stdio(false);
int n;
cin>>n;
int N=1;while(N<n)N*=2;
for(int i=1;i<2*N+2;i++)tree[i].resize(9);
for(int i=1;i<=n;i++){
    for(int a=1;a<=8;a++)cin>>tree[N+i-1][a];
};
vector<int> P={0,1,2,3,4,5,6,7,8};
for(int i=N+n;i<=2*N-1;i++)tree[i]=P;
tworz(N);
int k;cin>>k;
for(int i=0;i<k;i++){
    vector<int> D(9);
    for(int j=0;j<=8;j++)cin>>D[j];
    update(D[0],D,N);
    for(int j=1;j<=8;j++)cout<<tree[1][j]<<" ";
    cout<<"\n";
}


return 0;
}
