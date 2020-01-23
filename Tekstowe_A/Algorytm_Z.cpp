//Prefikso-Prefix
#include<bits/stdc++.h>
using namespace std;

void pref(string & T , int n , int W[] ){ //tablica //rozmiar element za ostatnim //tablica do zapisu wynikow
W[0]=0;
int k=1; //najdalej siegajacy prefix
    for(int i=1;i<n;i++){
        if(i < k + W[k]-1)
        W[i]=min(W[i-k], k+W[k]-i);
        else
        W[i]=0;
        while( T[ i+W[i] ]== T[ W[i] ] )
         W[i]++;
        if(i+W[i] > k + W[k])k=i;

    }


}

main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
string a;
cin>>a;
int W[int(1e6)+5];
pref(a,a.size(),W);
for(int i=0;i<a.size();i++)
cout<<W[i]<<" ";
cout<<endl;
}




return 0;
}
