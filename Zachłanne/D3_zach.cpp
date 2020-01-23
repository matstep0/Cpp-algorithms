//elfy i orkowie
#include<bits/stdc++.h>
using namespace std;
vector<int> O;
vector<int> E;

int main(){
 ios_base::sync_with_stdio(false);
    int Z;
    cin>>Z;
    while(Z--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int d;
            cin>>d;
            O.push_back(d);
        };
        for(int i=0;i<n;i++){
            int d;
            cin>>d;
            E.push_back(d);
        };
    sort(O.begin(),O.end());
    sort(E.begin(),E.end());
    int p_O=0;int k_O=O.size()-1;
    int p_E=0;int k_E=E.size()-1;
    int wynik=0;
    while(p_O<=k_O){
        if(O[p_O]<E[p_E]){p_O++;k_E--;wynik--;continue;};
        if(O[k_O]<E[k_E]){p_O++;k_E--;wynik--;continue;};
        if(O[p_O]>E[p_E]){p_O++;p_E++;wynik++;continue;};
        if(O[k_O]>E[k_E]){k_O--;k_E--;wynik++;continue;};
        //remisy
        if(O[p_O]<E[k_E]){
            p_O++;k_E--;wynik--;
        }
        else
            break;
    };
    cout<<wynik*200<<"\n";
    O.resize(0);
    E.resize(0);
};



return 0;
}
