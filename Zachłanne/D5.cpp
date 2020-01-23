#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second
struct sklep{
    int l;
    int r;
    int c;
};
bool operator<(sklep a , sklep b){
return !(a.c<b.c);
};
sklep T[5004];
bool czysieda(vector<pair<int,int> >  P){ //czy da sie wziac wszyskie przedzialy
    sort(P.begin(),P.end());
  priority_queue<int,vector<int>,greater<int>> konce;
   auto it=P.begin();
   int teraz;
   while(it!=P.end()){
        int czas =(*it).st;
        teraz=czas;
        while(it!=P.end() and (*it).st==czas ){
            konce.push( (*it).nd );
            it++;
        };
        int roz;
        if(it==P.end() )roz=1e9-czas;
        else
        roz=(*it).st-czas;

      while(roz>0 and !konce.empty()){
       if(teraz>=konce.top() )return false;
       konce.pop();
       roz--;
       teraz++;
      };

   }
return true;
};

int main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>T[i].l>>T[i].r>>T[i].c;
    };
    sort(T,T+N);
    int wynik=0;
    vector<pair<int,int> > biore;//ktore biore
    for(int i=0;i<N;i++){
        biore.push_back(make_pair(T[i].l,T[i].r));
        if(czysieda(biore)==false){biore.pop_back();continue;};
        wynik+=T[i].c;
    };
    cout<<wynik<<"\n";
}


return 0;
}
