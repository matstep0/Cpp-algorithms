#include<bits/stdc++.h>
using namespace std;
const int roz=100000+5;
int lef[roz];
int rig[roz];
int number[roz];
int suma[roz];//ile wbilismy do tej pory

int main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
    int n;
    cin>>n;
    for(int i = 0 ;i<n;i++){
        cin>>lef[i]>>rig[i]>>number[i];
    };
    vector<pair<int,int> > konce;
    for(int i=0;i<n;i++){
        konce.push_back(make_pair(rig[i],i));
    };
    sort(konce.begin(),konce.end());
    int razem=0; //ile razem wbilismy
    for(int x=0;x<konce.size();x++){
        int w;//ile wczesnie wbilismy
        int i=konce[x].second;
        auto it= lower_bound(konce.begin(),konce.end(),make_pair(lef[i],-1));
        it--;
        if(it<konce.begin())w=0;
        else w=suma[it-konce.begin()];

        int wbic=number[i]-(razem-w);
        wbic=max(wbic,0);
        suma[x]=razem+wbic;
        razem+=wbic;
    }
    cout<<razem<<"\n";


}


return 0;
}
