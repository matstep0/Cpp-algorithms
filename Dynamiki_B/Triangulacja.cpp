#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define roz 203
#define int long long
pair<int,int> wie[roz];
int wynik[roz][roz];
int krok[roz][roz]; //jaki byl najlepszy przedzial dla [i] [j]
int dl(int i,int j){
int w=(wie[i].st-wie[j].st)*(wie[i].st-wie[j].st)+ (wie[i].nd- wie[j].nd)*(wie[i].nd- wie[j].nd);
return w;
}

void odtworz(int i,int j){
if(i+1==j){return;};
cout<<i<<" "<<j<<" ";
int k=krok[i][j];
odtworz(i,k);
odtworz(k,j);
return;
}
main(){
int Z;
cin>>Z;
while(Z--){
int n;
cin>>n;
for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
    krok[i][j]=0;
for(int i=0;i<n;i++){
cin>>wie[i].st>>wie[i].nd;
}
for(int i=0;i<n;i++){
    krok[i][i+1]=-1;
}
for(int i=0;i+1<n;i++)
wynik[i][i+1]=0;

for(int s=2;s<n;s++)
    for(int i=0;i+s<n;i++)
    {
        int j=i+s;
        int MAX=1000000000000;
        for(int k=i+1;k<j;k++)
        {
           int w=wynik[i][k]+wynik[k][j]+dl(i,j);
           if(w<=MAX){MAX=w;krok[i][j]=k;wynik[i][j]=w;};
        }
    }
wynik[0][n-1]-=dl(0,n-1);
cout<<wynik[0][n-1]<<" ";
int k=krok[0][n-1];
odtworz(0,k);
odtworz(k,n-1);
cout<<endl;
}

return 0;
}
