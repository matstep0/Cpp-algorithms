#include<bits/stdc++.h>
using namespace std;

int main(){
    int i=1;
    while(i++){
        system("./gen > test.in");
        if(system("./main < test.in > test.out"))break;
        cout<<i<<endl;
    }


return 0;
}
