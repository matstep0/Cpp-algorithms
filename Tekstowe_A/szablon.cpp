#include<bits/stdc++.h>
using namespace std;
int P[500005];
void pref_pref(string & s){
int k=0;//najdalej siegajacy
for(int i=1;i<s.size();i++){
    if(i<=k+P[k]-1)
        P[i]=min(P[i-k],k+P[k]-i);
    while(s[i+P[i]]==s[ P[i] ] )
    P[i]++;
    if(i+P[i]>k+P[k])
    k=i;
}
return;
}

bool czy_jest(int x,int S){//czy biorac prefixy nie wieksze niz x da się przejsc tablice
int najd=x;//zasieg do nastepngo prefixu
int wsk=0;
while(najd>0){
najd--;
wsk++;
najd=max(najd,P[wsk]);
najd=min(x,najd);
}
if(wsk>=S)return true;
else
return false;

}
int bin_search(vector<int> T,int dl){
int p=0;
int q=T.size()-1;
while(p<q){
    int s=(p+q)/2;
    if(czy_jest(T[s],dl))
    q=s;
    else
    p=s+1;
}
return T[p];
}

int main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
string s;
cin>>s;
pref_pref(s);
vector<int> rozw;
for(int i=0;i<s.size();i++)
    if(i+P[i]==s.size())
        rozw.push_back(P[i]);


reverse(rozw.begin(),rozw.end());
rozw.push_back(s.size());

//for(int i=0;i<rozw.size();i++)
//cout<<rozw[i]<<endl;
//cout<<czy_jest(rozw[i],s.size())<<endl;

cout<<bin_search(rozw,s.size())<<endl;
/*
for(int i=0;i<s.size();i++)
cout<<P[i]<<" ";
cout<<endl;
*/
for(int i=0;i<s.size()+1;i++)
P[i]=0;

}
return 0;
}
