#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);
srand(random_device()()  );
    int Z=rand()%1+1;
    cout<<Z<<"\n";
 while(Z--){
    int n=rand()%4+2;
    cout<<n<<"\n";
    for(int i=0;i<n;i++){
        cout<<rand()%10<<" "<<rand()%10<<"\n";
    }


 }


return 0;
}
