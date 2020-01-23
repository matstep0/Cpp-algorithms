#include<bits/stdc++.h>
using namespace std;
//pref zwraca tablice W z prefiksami
int A[100003];//slowo
int W_L[100003];//wyniki gdy w lewo
int W_P[100003];//wyniki gdy w prawo
int PL[100003]; //tablica do liczenie w prawo

void pref(int T[] , int n , int W[] ){ //tablica //rozmiar element za ostatnim //tablica do zapisu wynikow
W[0]=0;
int k=1; //najdalej siegajacy prefix
    for(int i=1;i<n;i++){
        if(i < k + W[k]-1)
        W[i]=min(W[i-k], k+W[k]-i);
        else
        W[i]=0;
        while( T[ i+W[i] ]== T[ W[i] ] and i+W[i]<n )
         W[i]++;
        if(i+W[i] > k + W[k])k=i;
    }
}

bool powL(int p,int q){ //sprawdzam czy jest powtórzenie na w tak pierwszy wyraz jest na lewo od srodka
int s=(p+q)/2;
reverse(A+p,A+s+1);

pref(A+p,s-p+1,W_L);
reverse(W_L,W_L+s-p+1);
reverse(A+p,A+s+1);
for(int i=0;i+s<=q;i++){
PL[i]=A[i+s];
};
PL[q-s+1]=-1;
for(int i=0;i+p<s;i++){
PL[(q-s+1)+1+i ]=A[i+p];
}

pref(PL,q-p+2,W_P);


for(int i=0;i+p<s;i++)
if(W_L[i] + W_P[(q-s)+2+i] >=s-(p+i)+1 )return true;

return false;
}
bool powP(int p,int q){ //sprawdzam czy jest powtórzenie na w tak pierwszy wyraz jest na lewo od srodka
int s=(p+q)/2;


pref(A+s,q-s+1,W_P);


for(int i=0;i+s+1<=q;i++){
PL[i]=A[i+s+1];            //tak naprawde to LP rev
};
PL[q-s]=-1;
for(int i=0;i+p<=s;i++){
PL[(q-s+1)+i ]=A[i+p];
}
reverse(PL,PL+q-p+2);
pref(PL,q-p+2,W_L);
reverse(W_L,W_L+q-p+2);
for(int i=0;i+s<=q;i++)
if(W_L[i-1] + W_P[i] >=i+1 )return true;//uwaga

return false;
}

bool szukaj(int p,int q){
if(p==q)return false;
if(p+1==q)
    if(A[p]==A[q])return true;
    else
    return false;
int s=(p+q)/2;

if( szukaj(p,s) )return true;
if(szukaj(s+1,q))return true;

if(powL(p,q))return true;
if(powP(p,q))return true;



return false;

}

int main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
int n;
cin>>n;

for(int i=0;i<n;i++)
cin>>A[i];


if(szukaj(0,n-1) )cout<<"TAK";
else
cout<<"NIE";
cout<<endl;

}


return 0;
}
