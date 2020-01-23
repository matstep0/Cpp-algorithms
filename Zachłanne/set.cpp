#include<bits/stdc++.h>
using namespace std;
int main(){
set<int> A;
A.insert(5);
A.insert(3);
A.insert(8);
for(auto it=A.begin();it!=A.end();it++)
cout<<(*it)<<endl;


return 0;
}
