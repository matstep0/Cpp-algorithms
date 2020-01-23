#include<bits/stdc++.h>
using namespace std;
#define sasiad first
#define wynik second
vector< pair<int,int> > T[1000005]; //first oznacza sasiada second czy wygrywa zaczynajacy
// wynik -1 nieodwiedzona 0 przegrana 1 wygrana

bool dfs(int x,int p){//czy wygrywam wchodz
if(T[x].size()==1 and T[x][0].sasiad==p)return 0;//przegrana

for(int i=0;i<T[x].size();i++){
    int wie=T[x][i].sasiad;
    if(wie==p)continue;
    if(T[x][i].wynik==-1){T[x][i].wynik=dfs(wie,x);};
}

for(int i=0;i<T[x].size();i++){
    int wie=T[x][i].sasiad;
    if(wie==p)continue;
   if(T[x][i].wynik==0)return 1;
}
return 0;

}
int wygryw(int x){
    for(int y=0;y<T[x].size();y++){
        if(T[x][y].wynik==0)
        return 1;
    }
return 0;
}
void clean(int n){
for(int i=1;i<=n;i++)
T[i]=vector<pair<int,int> > ();
}

int main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
int n;
cin>>n;
for(int i=1;i<=n;i++){
int il=0;// ilosc krawedzi wychodzacych z i-tego wierzcholka
cin>>il;
for(int j=0;j<il;j++){
    int x;//wierzholek docelowy
    cin>>x;
    x++;
    pair <int,int> d(x,-1);
    T[i].push_back(d);
}
};
/*
for(int i=1;i<=n;i++){
    for(int j=0;j<T[i].size();j++)
        cout<<T[i][j].sasiad;
        cout<<endl;
}
*/
for(int i=1;i<=n;i++){
dfs(i,0);
};

for(int i=1;i<=n;i++){
if(wygryw(i))cout<<"W";
else cout<<"P";
}
cout<<endl;
clean(n);



}

return 0;
}
