#include<bits/stdc++.h>
using namespace std;

const int roz=(int)1e6 + 5;

int PI[int(1e6) + 5]; // PI[i] najdłuższy pref-suf w słowie S(a do i)
char S[1000005];


int pow(char S[],int n){ //wksaznik do tablicy i n czyli SIZE
//Tab KMP
//for(int i=0;i<n;i++)
//printf("%c",S[i]);


int PI[roz];
PI[0]=0;
int w=0;
for(int i=1;i<n;i++){


while(w>0 and S[w]!=S[i])
w=PI[w-1];

if(S[w]==S[i])
w++;
PI[i]=w;
}
int naj=n-PI[n-1];
if(n%naj!=0)return 1;
else return n/naj;

}
main(){

int Z;
scanf("%d",&Z);
while(Z--){
char S[roz];
scanf("%s",S);
int n=strlen(S);

printf("%d\n",pow(S,n));


}



return 0;
}


