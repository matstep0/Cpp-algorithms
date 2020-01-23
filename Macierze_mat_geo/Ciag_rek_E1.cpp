#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int> > M0;
vector<int> wyrazy;
void mnoz(vector<vector<int> >  A,vector<vector<int> > B,vector<vector<int>  >& ret){ //mnozy macierz przez samo siebie
vector<vector<int>  >W(A.size());
int k=A.size()-1;
for(int i=0;i<=A.size()-1;i++)W[i].resize(A.size());
 for(int i=1;i<=k;i++)
  for(int j=1;j<=k;j++){
    W[i][j]=0;
    for(int kp=1;kp<=k;kp++){
        W[i][j]+=A[i][kp]*B[kp][j];
        W[i][j]%=1000;
    };
  };
  ret=W; //zwraca mi macierz do funkcji
return;
};

void potega(vector<vector<int> > & M,int x,vector<vector<int> > & ret){
if(x==1){
ret=M;
return;
}
    auto W=M;
    if(x%2==0){
        potega(M,x/2,W);
        mnoz(W,W,W);
    };
    if(x%2==1){
        potega(M,x-1,W);
        mnoz(W,M0,W);
    };
   ret = W;

}

main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
    int k,m;
    cin>>k>>m;
 M0.resize(k+1);
for(int i=1;i<=k;i++){M0[i].resize(k+1);};
for(int i=1;i<=k;i++)
for(int j=1;j<=k;j++)
    M0[i][j]=0;
for(int i=1;i<=k;i++){cin>>M0[1][i];M0[1][i]%=1000;};

for(int j=1;j<=k;j++)M0[j][j-1]=1;

wyrazy.resize(k+1);
for(int i=k;i>=1;i--)cin>>wyrazy[i];
vector<vector<int> > W=M0;
int wynik=0;
if(m<=k){wynik=wyrazy[m];goto C;};

potega(M0,m-k,W);

for(int i=1;i<=k;i++){wynik+=W[1][i]*wyrazy[k+1-i];wynik%=1000;}
C:
if(wynik<10){cout<<"00"<<wynik<<endl;continue;}
if(wynik<100){cout<<"0"<<wynik<<endl;continue;}

cout<<wynik%1000<<endl;



}

return 0;
}
