#include<bits/stdc++.h>
using namespace std;
const int roz=100000+5;
int lef[roz];
int rig[roz];
int number[roz];
int suma[roz];//ile wbilismy do tej pory
int wczesniej[roz];//wskazuje indeks wczesniejszego konca przed poczatkiem naszego przedzialu

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
    vector<pair<int,int> > poczatki;
    for(int i=0;i<n;i++){
        konce.push_back(make_pair(rig[i],i));
        poczatki.push_back(make_pair(lef[i],i));
    };
    sort(konce.begin(),konce.end());
    sort(poczatki.begin(),poczatki.end());
    int wsk=-1; //koniec
    int wsk2=0; //poczatek
    for(wsk2=0;wsk2<poczatki.size();wsk2++){
        while(konce[wsk+1].first<poczatki[wsk2].first){
            wsk++;
        };
        wczesniej[poczatki[wsk2].second]=wsk;
    };
    //cout<<"W::"<<wczesniej[0]<<" "<<wczesniej[1];

    int razem=0; //ile razem wbilismy
    for(int x=0;x<konce.size();x++){
        int w;//ile wczesnie wbilismy
        int i=konce[x].second;
        if(wczesniej[i]==-1)w=0;
        else w=suma[wczesniej[i]];

        int wbic=number[i]-(razem-w); wbic=max(wbic,0);
        suma[x]=razem+wbic;
        razem+=wbic;
       // cout<<"x:"<<x<<" w:"<<w<<"razem"<<razem<<endl;
    }
    cout<<razem<<"\n";
    fill(lef,lef+n,0);
    fill(rig,rig+n,0);
    fill(suma,suma+n,0);
    fill(wczesniej,wczesniej+n,0);

}


return 0;
}
