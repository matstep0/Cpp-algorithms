#include<bits/stdc++.h>
using namespace std;
int T[1003];
int Sum_P[1003];
int R[1003][1003]; //ile zje gracz rozpoczynajacy
int NR[1003][1003];//ile zje gracz nierozpoczynajcy
int main(){
int Z;
scanf("%d",&Z);
while(Z--){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
scanf("%d",&T[i]);
}
for(int i=0;i<n;i++){
R[i][i]=T[i];
NR[i][i]=0;
}
for(int d=1;d<n;d++)
    for(int i=0;i+d<n;i++){
        int j=i+d;
        R[i][j]=max(T[i]+NR[i+1][j],T[j]+NR[i][j-1]);
        NR[i][j]=min(R[i][j-1],R[i+1][j]);
    }

printf("%d\n",R[0][n-1]);



}
return 0;
}
