#include<bits/stdc++.h>
using namespace std;
int main(){
srand(random_device()());
    int Z=rand()%3+1;
    cout<<Z<<endl;
    while(Z--){
        int n1=rand()%5+1;
        int n2=rand()%5+1;
        int m=rand()%n1*n2/4+3;
        cout<<n1<<" "<<n2<<" "<<m<<" "<<endl;
        for(int i=0;i<m;i++)
        {int x=rand()%n1+1;
         int y=rand()%n2+1;
         cout<<x<<" "<<y<<endl;

        }


    }


return 0;
}
