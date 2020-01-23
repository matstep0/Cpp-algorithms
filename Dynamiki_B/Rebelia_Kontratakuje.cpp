#include<bits/stdc++.h>
using namespace std;
const int roz=2001;
int dj[roz];//odlegolosc itego
int tj[roz];//czas itego
int LM[roz][roz];//min czas koniec L
int PM[roz][roz];//min czas koniec P
const int nies=1e9+1000;
int dl(int i,int j){
return (dj[j]-dj[i]);
}
int main(){

int Z;
scanf("%d",&Z);
while(Z--){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++)
scanf("%d %d",&dj[i],&tj[i]);

for(int i=0;i<n;i++){
LM[i][i]=0;
PM[i][i]=0;
}

for(int s=1;s<n;s++)
    for(int i=0;i+s<n;i++){
    int j=i+s;

    LM[i][j]=min(LM[i+1][j]+dl(i,i+1),PM[i+1][j]+dl(i,j));

    if(LM[i][j]>=tj[i]) LM[i][j]=nies;

    PM[i][j]=min(LM[i][j-1]+dl(i,j),PM[i][j-1]+dl(j-1,j));
    if(PM[i][j]>=tj[j])PM[i][j]=nies;
    }
int wyn=min(LM[0][n-1],PM[0][n-1]);

//printf("%d\n",wyn);
if(wyn==nies)
    printf("FAIL\n");
else
    printf("%d\n",wyn);


}
return 0;
}
