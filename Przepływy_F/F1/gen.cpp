#include<bits/stdc++.h>
using namespace std;
int c[101][101];
int main(){
srand(random_device()());
int Z=rand()%3+1;
cout<<Z<<endl;
while(Z--){
    int n=rand()%10+2;
    cout<<n<<endl;
    for(int i=0;i<2*n;i++){
        A:;
        int x=rand()%n+1;
        int y=rand()%n+1;
        if(x==y)goto A;
        c[min(x,y)][max(x,y)]=rand()%10;
    }

    for(int i=1;i<=n;i++){
     for(int j=1;j<=n;j++){
        cout<<c[i][j]<<" ";
     }
     cout<<endl;
     }

}

return 0;
}
