//dynamik z bardzo nietrywialnym doborem podzadania
#include<bits/stdc++.h>
using namespace std;
bool P[25][25]; //wiersze  kolumny
long long rozstawienia[1<<25]; //ilosc mozliwosci dla zbirru A

bool nalezy(int S,int x){//czy x nalezy do S
if( (S & (1<<x) ) > 0)return true;
return false;
}

int mocZ(int S){
int k=0;
while(S>0){

if(S%2==1){k++;S--;};
S/=2;

}

return k;
}

int main(){
ios_base::sync_with_stdio(false);

int Z;
cin>>Z;
while(Z--){
int n;
cin>>n;
for(int i=0;i<n;i++){
string a;
cin>>a;
    for(int k=0;k<n;k++){
        if(a[k]=='.')P[i][k]=false;
        else P[i][k]=true; //dziura
    }
};
rozstawienia[0]=1;

for(int S=1;S<= ( (1<<n)-1);S++){
    rozstawienia[S]=0;
    for(int i=0;i<n;i++){
        if(nalezy(S,i) and P[i][mocZ(S)-1]==false)
        rozstawienia[S]+=rozstawienia[S-(1<<i)];
    }

}
cout<<rozstawienia[(1<<n) -1]<<endl;

}
return 0;
}
