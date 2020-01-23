#include<bits/stdc++.h>
using namespace std;
int fast_power(int a,int k,int p){ //a do k mod p
    if(k==0)return 1;
    if(k%2==0){
        int w=fast_power(a,k/2,p);
        return ( (long long)w*w)%p;
    };
    if(k%2==1){
        int w=fast_power(a,k-1,p);
        return ( (long long)w*a)%p;
    };
}

main(){
int Z;
cin>>Z;
while(Z--){
    int a,b,p;
    cin>>a>>b>>p;
    if(a%p==0){cout<<-1<<endl;continue;};
    vector<int> mpier(1);
    vector<pair<int,int> > wiel(1); //first wartosc second numer wielokrotnoci pier upper
    wiel[0]=make_pair(0,0);
     mpier.push_back(a%p);
    for(int i=2;i*i<=p;i++){
        mpier.push_back( (long long)((long long)mpier[i-1]*(long long)a)%(long long)p );
    };
    wiel.push_back(make_pair(mpier.back(),1) );
    for(int i=2;i<=mpier.back();i++){
      wiel.push_back(
        make_pair( (long long)( (long long)wiel[i-1].first*(long long)mpier.back()%(long long)p), i )
        );
    };
    sort(wiel.begin()+1,wiel.end());
    int wynik=p;
    for(int i=1;i<mpier.size();i++){
        int v=((long long)b*fast_power(a,p-2,p))%(long long)p;
        auto it=upper_bound(wiel.begin()+1,wiel.end(),make_pair(v,0));
        if((*it).first==v){wynik=min(wynik,(*it).second*mpier.back()+i);};
    };
    if(wynik<p)cout<<wynik<<endl;
    else
        cout<<-1<<endl;


}

}
