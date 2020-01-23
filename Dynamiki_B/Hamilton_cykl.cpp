//najduje cykl hamiltona w n^2 *2^n
#include<bits/stdc++.h>
using namespace std;
bool macierz[17][17]; //czy a,b sasiaduja ze soba
bool H_cykl[1<<17][17]; //czy da sie obejsc zbior zaczynajac w 0 i koczac w x
int  poprzednik[1<<17][17]; //poprzednik w cyklu
bool x_c_S(int S,int x){//czy x nalezy do S
if( (S & 1<<x) > 0)return true;
return false;
}
void clean(int n){
int roz=1<<n;
for(int i=0;i<roz;i++)
    for(int j=0;j<n;j++)
        {
            poprzednik[i][j]=0;
            H_cykl[i][j]=false;
        }

for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        macierz[i][j]=false;
}
void dec2bin(long long l){

 if (l==1){cout<<1;return;};
 dec2bin(l/2);
 cout<<l%2;
}

void odtworz(int S,int x){
    if(S==1)return;
    cout<<x<<" ";
    int y=poprzednik[S][x];
    int S2=S-(1<<x);
    odtworz(S2,y);

}
int main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
    int n,m;
    cin>>n>>m;
    n++;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        macierz[a][b]=true;
        macierz[b][a]=true;
    }
//wczytalem dane

    H_cykl[1][0]=true;

    for(int S=1;S<=((1<<n)-1);S++){
    // dec2bin(S);
     //cout<<endl;
        for(int x=1;x<n;x++){
            if(x_c_S(S,x) ){
            //cout<<"x:"<<x<<endl;
                for(int y=0;y<n;y++){
               // cout<<"y:"<<y<<endl;
                if( y!=x and x_c_S(S,y)  and macierz[x][y] ){
                   // cout<<"a"<<endl;
                   if( H_cykl[S - (1<<x)][y] ){
                    H_cykl[S][x]=true;
                    poprzednik[S][x]=y;
                    }
                   }
                }
           //   cout<<" wynik"<<H_cykl[S][x]<<endl;
            }

        }

       }
int P=(1<<n)-1;
bool ist=false;
int konc=0;
    for(int y=1;y<n;y++){
        if(H_cykl[P][y] and macierz[0][y]){ist=true;konc=y;}
    }
if(ist){cout<<"TAK"<<endl;odtworz(P,konc);}
else cout<<"NIE"<<endl;
clean(n);
}
return 0;
}
