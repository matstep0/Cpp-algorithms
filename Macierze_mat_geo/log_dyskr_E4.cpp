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
    vector<int> mpier;
    vector<pair<int,int> > wiel; //first wartosc second numer wielokrotnoci pier upper
     mpier.push_back(1%p);
    for(int i=1;(i-1)*(i-1)<=p;i++){
        mpier.push_back( (long long)((long long)mpier[i-1]*(long long)a)%(long long)p );
    };
    wiel.push_back(make_pair(1,0));
    wiel.push_back(make_pair(mpier.back(),1) );
    for(int i=2;i*i<p;i++){
      wiel.push_back(
        make_pair( (long long)( (long long)wiel[i-1].first*(long long)mpier.back()%(long long)p), i )
        );
    };
    sort(wiel.begin(),wiel.end());
    int wynik=p;
    for(int i=0;i<mpier.size();i++){
        int v=((long long)b*fast_power(mpier[i],p-2,p))%(long long)p;
        auto it=upper_bound(wiel.begin(),wiel.end(),make_pair(v,-3));
        if(it==wiel.end())continue;
        if((*it).first==v){wynik=min(wynik,(*it).second*((int)mpier.size()-1)+i);};
    };
    if(wynik<p)cout<<wynik<<endl;
    else
        cout<<-1<<endl;


}

}
