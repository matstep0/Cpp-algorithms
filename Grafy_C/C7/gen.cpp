#include<bits/stdc++.h>
using namespace std;

int main(){
random_device(rd);
srand(rd());
int Z=2;
cout<<Z<<endl;
while(Z--){
    int n=rand()%100000+1;
    cout<<n<<endl;
    for(int i=1;i<=n;i++)
        cout<<rand()%100000+1<<" ";
        cout<<endl;
    for(int i=2;i<=n;i++){
        cout<<i<<" "<<rand()%(i-1)+1<<" "<<rand()%10000+1;cout<<endl;
    }

}



return 0;
}
