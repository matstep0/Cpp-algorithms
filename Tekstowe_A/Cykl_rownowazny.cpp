#include<bits/stdc++.h>
using namespace std;
int PI[int(1e8)+5]; //najwiekszy

main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
    int n;
    cin>>n;
    string W;
    string T;
    cin>>W;
    cin>>T;
    W+="#";
    W+=T+T;

       bool solve = false; //czy znalazlem
    PI[0]=0;
    int j=0;//liczba dopasowanych
    for(int i=1;i<W.size();i++){
        while(j>0 && W[j]!=W[i])
            j=PI[j-1];
        if(W[j]==W[i])
        j++;
        if(j==n){solve = true;}
        PI[i]=j;
        }

     PI[0]=0;
     j=0;
     reverse(W.begin(), W.begin()+n );

    for(int i=1;i<W.size();i++){
        while(j>0 && W[j]!=W[i])
            j=PI[j-1];
        if(W[j]==W[i])
        j++;
        if(j==n){solve = true;};
        PI[i]=j;
        }

   if(solve)cout<<"IDENTYCZNE"<<endl;
   else cout<<"ROZNE"<<endl;

}
return 0;
}
