//drzewo przezialowe ze spychaniem
#include<bits/stdc++.h>
using namespace std;
const int roz=2*1e7;
#define  maxim first
#define ust second
pair<int,int>  tree[roz]; //maxim, ustawione
void push(int x){ //pusuje wartosć z noda
    tree[2*x].ust=tree[2*x+1].ust=tree[2*x].maxim=tree[2*x+1].maxim=tree[x].ust;
    tree[x].ust=0;
}
int M(int a, int b,int x,int p,int q){ //zczytuje maxa na przedziale i ustawia
//cout<<"M"<<endl;
if(a==p and b==q)return max(tree[x].ust,tree[x].maxim);
if(tree[x].ust!=0)push(x);
int s=(p+q)/2;
int w1=0,w2=0;
if(a<=s)w1=M(min(a,s),min(b,s),x*2,p,s);
if(b>s)w2=M(max(s+1,a),max(s+1,b),x*2+1,s+1,q);
return max(w1,w2);
}
void ustal(int a, int b,int x,int p,int q,int ustaw){
//cout<<"U"<<endl;
if(a==p and b==q){tree[x].ust=ustaw;tree[x].maxim=ustaw;return;}
if(tree[x].ust!=0)push(x);
int s=(p+q)/2;
if(a<=s)ustal(min(a,s),min(b,s),x*2,p,s,ustaw);
if(b>s)ustal(max(s+1,a),max(s+1,b),x*2+1,s+1,q,ustaw);
tree[x].maxim=max(tree[2*x].maxim,tree[2*x+1].maxim);
return;
}
int main(){
ios_base::sync_with_stdio(false);
int d, n;
cin>>d>>n;
int D=1;
while(D<d)D*=2;
while(n--){
    int l,x;
    cin>>l>>x;
    int maxi=M(x,x+l-1,1,0,D-1);
    ustal(x,x+l-1,1,0,D-1,maxi+1);
}
int wynik=tree[1].maxim;
cout<<wynik<<"\n";
return 0;
}
