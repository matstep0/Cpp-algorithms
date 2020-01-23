#include<bits/stdc++.h>
using namespace std;
const int roz=1e6+5;
#define st first
#define nd second
int T[roz];
int wynik(int a,int b){
    int w=0;
    for(int i=a;i<=b;i++)
        for(int j=i+1;j<=b;j++){
            if(T[j]<T[i]){w++;}
        }
    return w;
}
main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
int n;
cin>>n;
for(int i=1;i<=n;i++)cin>>T[i];
int k;
cin>>k;
for(int i=0;i<k;i++){
    int a,b;
    cin>>a>>b;
    cout<<wynik(a,b)<<endl;
}
}
return 0;
}
