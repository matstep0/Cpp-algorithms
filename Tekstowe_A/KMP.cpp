#include<bits/stdc++.h>
using namespace std;



int PI[int(1e6) + 5]; // PI[i] najdłuższy pref-suf w słowie S(a do i)
char S[1000005];
main(){

int Z;
cin>>Z;
while(Z--){
string a;
string S="#";
cin>>a;
S+=a;


int j=0; //liczba dopasowanych
PI[1]=0;
    for(int i=2;i<S.size();i++){
        while(j>0 && S[i]!=S[j+1])
            j=PI[j];
        if(S[i]==S[j+1])
        j++;

        PI[i]=j;
    }
    int M=S.size()-1 - PI[S.size()-1];
    if ( (S.size()-1 )%M==0 )
    cout<<(S.size()-1)/M<<endl;
else cout<<1<<endl;


}



return 0;
}
