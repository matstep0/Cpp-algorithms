//znajduje najmniejsza odleglosc pomiedzy  pare punktow
#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second
bool comp(pair<int,int> a, pair<int,int> b){
    if(a.nd<b.nd)return true;
    if(a.nd>b.nd)return false;
    if(a.nd==b.nd)return a.st<b.st;
}
typedef long long ll;
pair<int,int> T[100004];
long long delta=1e9;
int n;
long long kwodl(pair<int,int> a,pair<int,int> b){
    ll w= ( (ll)a.first-b.first)*( (ll)a.first-b.first) +
    ( (ll)a.second-b.second)*( (ll)a.second-b.second);
    //cout<<w<<endl;
    return w;
};
 void f(int p,int q){
 //call stac
 //cout<<p<<" "<<q<<"\n";
    if(p==q){return;};
    int s=(p+q)/2;
    f(p,s);
    f(s+1,q);
    vector<pair<int,int> >P;
    P.push_back(T[s]);
      ll pion_x=T[s].first;
      int z1=s-1;int z2=s+1;
      while( z1>=p and (ll)(pion_x-T[z1].st)*(ll)(pion_x-T[z1].st)<delta){
            P.push_back(T[z1]);
            z1--;
      }  ;
      while( z2<=q and (ll)(T[z2].st-pion_x)*(ll)(T[z2].st-pion_x)<delta){
            P.push_back(T[z2]);
            z2++;
      };
      sort(P.begin(),P.end(),comp);
      for(int i=0;i<P.size();i++){
        for(int j=1;j<=8 and i+j<P.size();j++){
     //   cout<<kwodl(i,i+j)<<endl;
            delta=min(delta,kwodl(P[i],P[i+j] ) );
        }
      };

return;
}

int main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
delta=LLONG_MAX;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>T[i].first>>T[i].second;
    };
    sort(T,T+n);
    f(0,n-1);
    cout<<delta<<"\n";
}

return 0;
}
