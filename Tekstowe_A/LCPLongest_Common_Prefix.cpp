#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second

vector<pair<int,int> > slownik[16];

struct element{
int first;
int second;
int index;
};
bool porownaj(element a,element b){
if(a.st<b.st)return true;
else
if(a.st>b.st)return false;
return a.nd<=b.nd;


}
bool porownaj2(pair<int,int> a,pair<int,int> b){
return a.nd<b.nd;
}

vector<pair<int,int> > tworz(int k,int w){

  vector<element> pomoc;
    for(int i=0;i+k<slownik[w-1].size();i++){
        element a;
        a.st=slownik[w-1][i].st;
        a.nd=slownik[w-1][i+k].st;
        a.index=slownik[w-1][i].nd;
        pomoc.push_back(a);
    }
    sort(pomoc.begin(), pomoc.end(), porownaj);
    vector<pair<int,int>> wypluj;
    int var = 0 ;
    for(int i=0;i<pomoc.size();i++){
        pair<int,int> d;
        d.st=var;
        d.nd=pomoc[i].index;
        wypluj.push_back(d);
        if(i+1<pomoc.size() and (pomoc[i].st != pomoc[i+1].st or pomoc[i].nd != pomoc[i+1].nd ) )var++;
    }
    sort(wypluj.begin(),wypluj.end(),porownaj2);
    return wypluj;
}




int main(){

int Z;
cin>>Z;
while(Z--){
int n;
cin>>n;
string dow;
cin>>dow;
vector<int> mapa;
for(int i=0;i<n;i++)
{
if(dow[i]=='L')
mapa.push_back(0);
else
mapa.push_back(1);
}
int ile=1;;
while(ile<mapa.size())
ile*=2;
ile*=2;//dodatkowo
while(mapa.size()<ile)
mapa.push_back(-1);

vector<pair<int,int> > firstelement;
for(int i=0;i<mapa.size();i++){
pair<int,int> d;
d.st=mapa[i];
d.nd=i;
firstelement.push_back(d);
};

slownik[0]=firstelement;
for(int k=1,w=1;k<mapa.size();k*=2,w++)
slownik[w]=tworz(k,w);

int a=1;
int l=0;
while(a<ile/2)
{a*=2;l++;}

vector<pair<int,int> > T=slownik[l];
sort(T.begin(),T.end());
vector<int> miejsce(T.size()) ; //pokazuje gdize jest miejsce i tego sufixu
for(int i=0;i<miejsce.size();i++)
miejsce[ T[i].nd ]=i;

vector<int> podciag(miejsce.size()); //jakie jest najwieksza iloc wspólnych liter dla i oraz i +1 elementu
int ws=0;
for(int i=0;i<miejsce.size();i++){
int p=miejsce[i];
while(p+1<T.size() and T[p].nd+ws<n and dow[T[p].nd+ws] == dow[T[p+1].nd+ws])ws++;
podciag[p]=ws;
if(ws>0)ws--;
}
vector<int> M(miejsce.size());
for(int i=0;i<miejsce.size();i++){
int p=miejsce[i];
if(p-1>0)M[i]=max(podciag[p-1],podciag[p]);
else
M[i]=podciag[p];

}
for(int i=0;i<podciag.size();i++)
cout<<podciag[i]<<" "<<endl;
cout<<endl;


}
return 0;
}
