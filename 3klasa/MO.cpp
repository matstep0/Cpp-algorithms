#include<bits/stdc++.h>
using namespace std;
const int roz=1e6+5;
#define st first
#define nd second
int T[roz];
int sqrtn;
#define int long long
bool comp(pair<int,int> a, pair<int,int> b){ // do sortowania pierwiastkowego
    if(a.st/sqrtn<b.st/sqrtn)return true;
    if(a.st/sqrtn>b.st/sqrtn)return false;
    return a.nd<b.nd;
};
int tree[(int)(4*1e6)]; //drzewo licznikowe //suma na przedziale
int bledy=0;
int suma(int a, int b,int D){ //ile jest liczb wiekszy od //suma na przedziale
    a+=D-1;
    b+=D-1;
    int wynik=0;
    while(true){
        if(a%2==1){wynik+=tree[a];a++;}
        if(b%2==0){wynik+=tree[b];b--;}
        if(a>b)break;
        a/=2;
        b/=2;
    };
   return wynik;
}
void dodaj(int x,int D, bool L,int co=1/*1 jak 0 odejuuje*/){ //jak co jest 0 to usuwa //czy zlewej czy prawej
//L= 1 to dodaje z lewej
    int r=x;
    x=x+D-1;
    if(tree[x]==co)return;
    int bl=0;
    if(L){if(r-1>=1)bl=suma(1,r-1,D);}
    else {if(r+1<=D)bl=suma(r+1,D,D);}
    bledy+= bl*(co-tree[x]);
    tree[x]=co;

    x/=2;
    while(x>0){
        tree[x]=tree[2*x]+tree[x*2+1];
        x/=2;
    }
return;
}

main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
int n;
cin>>n;
sqrtn=1;
int D=1;
while(D<n)D*=2;
while(sqrtn*sqrtn<n)sqrtn++;
for(int i=1;i<=n;i++)cin>>T[i];
int k;
cin>>k;
vector<pair<int,int> > Q; //questions;
Q.reserve(k);
for(int i=0;i<k;i++){
    int a,b;
    cin>>a>>b;
    Q.push_back(make_pair(a,b));
};
auto kolejnosc=Q;
sort(Q.begin(),Q.end(),comp);
map< pair<int,int> , int> wyniki;
int index=0;
for(int cp=1;;cp++){ //counter to pierwiastkow
    fill(tree,tree+2*D+3,0);
    bledy=0;
    for(int i=Q[index].st;i<=Q[index].nd;i++)
        dodaj(T[i],D,0);
    int p=Q[index].st; int q=Q[index].nd;
    do{
        int c=Q[index].st;
        int d=Q[index].nd;
        while(q<=d){dodaj(T[q],D,0);q++;}
        if(p<c)while(p<c){dodaj(T[p],D,1,0);p++;}
        if(p>c)while(p>c){dodaj(T[p],D,1,1);p--;}
        dodaj(T[p],D,1);
        wyniki[make_pair(c,d)]=bledy;
        index++;
    }while(index<Q.size() and Q[index].st<cp*sqrtn);
    if(index==Q.size())break;
};
for(int i=0;i<kolejnosc.size();i++)cout<<wyniki[kolejnosc[i]]<<"\n";
cout<<"\n";
}
return 0;
}
