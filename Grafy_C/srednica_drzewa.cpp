

#include<bits/stdc++.h>
using namespace std;
const int roz=200005;
#define vertex first
#define d second
vector<pair<int,int> > T[roz];
bool odw[roz];
int odlA[roz];//odlegolosc od jedeego z srednicy drzewa
int odlB[roz]; //odlegosc od drugieg ze srednicy drzewa
int odl[roz];
int BFS(int x,int odl[],int n,bool zwroc=0){ //odlegolosc vertexuw od x liczona z x i zwraca
    queue<int> kolejka;
    odl[x]=0;
    odw[x]=true;
    kolejka.push(x);
    while(!kolejka.empty()){
        int wie=kolejka.front();
        kolejka.pop();
        for(int i=0;i<T[wie].size();i++){
            pair<int,int> xy = T[wie][i];
            if(!odw[xy.vertex]){
                odw[xy.vertex]=true;
                odl[xy.vertex]=odl[wie]+xy.d;
                kolejka.push(xy.vertex);
            }

        }
    }
    if(zwroc){
        return distance(odl, max_element(odl,odl+n+1)); //numer elementu czyli najw wierz
    }
    else return 0;
}
void odw_clean(int n){
for(int i=0;i<=n;i++)
odw[i]=0;
return;
}
void clean(int n){
    for(int i=0;i<=n;i++){
        odw[i]=0;
        T[i]=vector<pair<int,int> >();
        odlA[i]=odlB[i]=odl[i]=0;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int Z;
    cin>>Z;
while(Z--){
    int n;
    cin>>n;
    clean(n);
   for(int i=0;i<n-1;i++){
        int a,b,d;
        cin>>a>>b>>d;
        T[a].push_back(pair<int,int>(b,d));
        T[b].push_back(pair<int,int>(a,d));
   }
int A= BFS(1,odl,n,1);
odw_clean(n);
//cout<<A<<endl;
int B= BFS(A,odlA,n,1);
odw_clean(n);
//cout<<B<<endl;
BFS(B,odlB,n);
    for(int i=1;i<=n;i++){
        cout<<max(odlA[i],odlB[i])<<" ";
    }
    cout<<endl;





}

return 0;
}
