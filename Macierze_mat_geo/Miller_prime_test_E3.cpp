#include<bits/stdc++.h>
using namespace std;
long long arra[13]={ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
long long fast_power(long long a,long long p,long long m){
if(p==1)return a%m;
    if(p%2==0){
        long long v = fast_power(a,p/2,m);
        long long z= (__int128)( (__int128)v*(__int128)v%(__int128)m);
        return z;
    };
    if(p%2==1){
        long long v=fast_power(a,p-1,m);
        long long z=(__int128)( (__int128)v*(__int128)a%(__int128)m);
        return z;
    };

};
bool test(long long pm1,long long dwa,long long d,long long pod){ //testuje czy liczba jest potencjalnie pierwsza
     long long n=pm1+1;
     if(pod%n==0)return true;
   long long a=fast_power(pod%n,d,n);
 //  cout<<a<<" fast_power: "<<pod<<" "<<d<<" "<<n<<endl;
    if(a==1 or a==n-1)return true;
    for(int i=0;i<dwa-1;i++){
         long long z= (__int128)( (__int128)a*(__int128)a%((__int128)n));
        a=z;
        if(a==n-1)return true;
    };

    return false;
}

int main(){
srand(random_device()());
ios_base::sync_with_stdio(false);
int Z;

cin>>Z;
while(Z--){
long long x;
cin>>x;
if(x==1){cout<<"NIE"<<endl;continue;}
long long xm1=x-1;
long long dwoj=0;
while(xm1%2==0){
    dwoj++;
    xm1/=2;
};
//cout<<" "<<dwoj<<" "<<xm1<<endl;
for(int i=0;i<13;i++){
    long long ar=arra[i];
    if(test(x-1,dwoj,xm1,ar)==false){cout<<"NIE"<<endl;goto END;}
}
cout<<"TAK"<<endl;

END:;
}



}
