//stary sposób kompresji
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

const int roz=700;
const int nies=1e9;
int wynik[roz][roz];//jaki jest nalepsza mozliwa kompresja fragmentu
int Komp[roz][roz];//jak kompresowalismy
int Podz[roz][roz];//jak podzielilismy

int mas(char S[],int n){
int T[203];
for(int i=0;i<200;i++)
T[i]=0;

for(int i=0;i<n;i++)
T[int(S[i]-'a') ]++;

int m=0;
for(int i=0;i<200;i++)
m=max(m,T[i]);
return m;


}

int pow3(char S[],int n){
for (int d = 1;d<=(n)/2;d++){
if( n%d != 0 ) continue;
bool f = true;

for (int k = 0; k+d<n; k++)
{
if(S[k]!=S[k+d]) f = false;
}

if(f){
int powtorzenie = n/d;
return powtorzenie;
}

}
return 1;

}

bool iden(char  S[],int i,int i2,int x){
for(int a=0;a<x;a++){
if(S[i+a]!=S[i2+a])return false;
}
return true;
}

int pow2(char S[],int n){
for(int d=1;d<n;d++)
{   if(n%d!=0)continue;
    bool ide=1;
    for(int i=0,i2=i+d;i2<n;i+=d , i2+=d)
        if(!iden(S,i,i2,d)){ide=0;break;}
     if(ide)return  n/d;
}

return 1;
}



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

int dl(int k){
    stringstream ss;
    string temp;
    ss << k;
    ss >> temp;
    return temp.size();
}

void kompresuj(int i,int j,char S[]){
if(i==j){printf("%c",S[i]);return;};
int k=Podz[i][j];
if(k!=-1){kompresuj(i,k,S);kompresuj(k+1,j,S);}
else {
int p=Komp[i][j];
int s=(j-i+1)/p;
printf("%d(",p);
kompresuj(i,i+s-1,S);
printf(")");
}

return;

}

int main(){
/*
while(true){
char A[300];
scanf("%s",A);
int n=strlen(A);
cout<<pow2(A,n)<<pow3(A,n)<<pow(A,n)<<endl;
}
*/

int Z;
scanf("%d",&Z);


while(Z--){
char S[roz];
scanf("%s",S);
const int n=strlen(S);
bool kbool=false; //czy bede palowal
if(mas(S,n)> n/2)kbool=false;
//printf("%d\n",n);
for(int i=0;i<n;i++)
wynik[i][i]=1;

for(int d=1;d<n;d++)
    for(int i=0;i+d<n;i++)
    {   int j=i+d;
        //a) powtorzenie

        int k;
        if(kbool)k=pow3(S+i,j-i+1);
        else
        k=pow(S+i,j-i+1);

        int a=-1;
        int s=-1;
        if(k==1)
            a=(d+1)+2+dl(k);
        else{
            s=(d+1)/k;
            a=wynik[i][i+s-1]+2+dl(k);
            Komp[i][j]=k;
            }
      //  printf(" s:%d k:%d a:%d \n",s,k,a);
        //b) dzielimy
        int b=nies;
        for(int k=i;k<j;k++)
        {
            int w=wynik[i][k]+wynik[k+1][j];
            if(w<b){b=w;Podz[i][j]=k;}
        }
        if(a<b){wynik[i][j]=a;Podz[i][j]=-1;}
        else{wynik[i][j]=b;Komp[i][j]=-1;}


    }
//printf("\nwynik%d\n",wynik[0][n-1]);
kompresuj(0,n-1,S);
printf("\n");





}
return 0;
}
