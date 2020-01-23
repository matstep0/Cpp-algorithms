#include<bits/stdc++.h>
using namespace std;
int ciag[1000];
int wynik_K=0;
int wynik_L=0;
bool K(int ws){
 for(int i=0;i+1<ws;i++){
                int ile=1;
                while(i+1<ws and ciag[i]==ciag[i+1] ){
                    ile++;
                    i++;
                };
                    if(ile%2==0)return false;
                };
                return true;
};

bool L(int ws){
for(int i=0;i+1<ws;i++)
    if( (ciag[i]==2 and ciag[i+1]==0) or (ciag[i]==0 and ciag[i+1]==2) )return false;

return true;
}
void gen(int n,int ws){

    if(n==0){
        if(K(ws))wynik_K++;
        if(L(ws))wynik_L++;
        return;
    }
    ciag[ws]=0;
    gen(n-1,ws+1);
    ciag[ws]=1;
    gen(n-1,ws+1);
    ciag[ws]=2;
    gen(n-1,ws+1);
    return ;
};
int main(){
int x;
cin>>x;
for(int i=0;i<=x;i++){
gen(i,0);
cout<<wynik_K<<" "<<wynik_L<<endl;
wynik_K=0;
wynik_L=0;
}




return 0;
}
