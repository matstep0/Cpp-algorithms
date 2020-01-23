#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define int long long
const int roz=100005;
int L[roz]; //zasieg kebaba
int wynik[roz];
vector<pair<int,int>> T[roz]; //wierzch  d
int st[roz]; //stopien wierzcholka
int act_st[roz];
bool odw[roz];
bool czarny[roz]; //jesli spotkam czarny wierzcholek to jego powiazania usuwam
queue<int> stopniowa;
int cen_odl[roz]; //odleglosc wierzcholka od centroidu teraz


void read(int n);
void solve(int n);
void helper(int n,int c);
int centroid(int n,int x);
void clean(int n);

void clean(int n){
    for(int i=0;i<=n;i++){
        L[i]=0;
        wynik[i]=0;
        T[i]=vector<pair<int,int> > ();
        st[i]=0;
        odw[i]=0;
        czarny[i]=0;
        cen_odl[i]=0;
    }
    while(!stopniowa.empty())stopniowa.pop();

}
main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
    int n;
    cin>>n;
    read(n);
//wejscie
   solve(n);
for(int i=1;i<=n;i++){
    cout<<wynik[i]+1<<endl;
}
clean(n);

}



return 0;
}

void helper(int n,int c){//na 0 copiuje aktualny stan st na 1 resetuje odw na 2 oba
        if(c==0 || c==2){
            for(int i=1;i<=n;i++){
                act_st[i]=st[i];
            }
        }
        if(c==1 || c==2){
            for(int i=1;i<=n;i++){
                odw[i]=0;
            }
        }
        if(c==3){
            for(int i=1;i<=n;i++){
                cen_odl[i]=0;
            }
        }
};

bool dfs(int x){
    odw[x]=true;
    if(act_st[x]==1)stopniowa.push(x);
    for(int i=0;i<T[x].size();i++){
        pair<int,int> s=T[x][i];
        if(czarny[s.st])continue;
        if(!odw[s.st]){
            dfs(s.st);
        }
    }
}
bool ddfs(int x,int s,vector<int> & zrzut,vector<int> & lista){  //liczy odl od centroidu odleglosci
//zrzut jest wektorem do ktorego to wsadza
    odw[x]=true;
    zrzut.push_back(s);
    cen_odl[x]=s;
    lista.push_back(x);
    for(int i=0;i<T[x].size();i++){
        pair<int,int> a =T[x][i];
        if(!odw[a.st] and !czarny[a.st]){
            ddfs(a.st,s+a.nd,zrzut,lista);
        }
    }


}

 int centroid(int n,int x){ //wywoluje sie na grafie i znajduje jego centroid
    dfs(x);
    int wie=0;
    while(!stopniowa.empty()){
        wie=stopniowa.front();
        stopniowa.pop();
        for(int i=0;i<T[wie].size();i++){
            pair<int,int> s=T[wie][i];
            if(czarny[s.st])continue;

                act_st[s.st]--;
                if(act_st[s.st]==1)stopniowa.push(s.st);

        }
    }
return wie; //ostatni to jest centoid drzewa
 }
void licz(int n,int cen){  //dla danego centoidu puszcza sie i liczy wyniki
    vector<vector<int> >D; // odleglosci od centroidu w podrzewie
    vector<vector<int> > lista; //lista wierzcholkow w drzewie lista[i] podrzewo
    odw[cen]=true;
    for(int i=0;i<T[cen].size();i++){

        pair<int,int> a=T[cen][i];
        if(!odw[a.st] and !czarny[a.st]){
            D.push_back( vector<int> () );
            lista.push_back(vector<int> () );
            ddfs(a.st,a.nd,D.back(),lista.back() );
        }
    }
    //mam policzone odleglosci
    for(int i=0;i<D.size();i++){
        sort(D[i].begin(),D[i].end());
    };
    vector<int> calosc; //suma D
    for(int i=0;i<D.size();i++)
        for(int j=0;j<D[i].size();j++){
            calosc.push_back(D[i][j]);
        }
    sort(calosc.begin(),calosc.end());

    for(int i=0;i<lista.size();i++){
        for(int j=0;j<lista[i].size();j++){
            int ob=lista[i][j];
            if(L[ob]<cen_odl[ob])continue;
            int r=L[ob]-cen_odl[ob];
            wynik[ob]+=distance(calosc.begin(),upper_bound(calosc.begin(),calosc.end(),r))
            -distance(D[i].begin(),upper_bound(D[i].begin(),D[i].end(),r))+1;
        }
    }
    wynik[cen]+=distance(calosc.begin(),upper_bound(calosc.begin(),calosc.end(),L[cen]));
    czarny[cen]=true;
    for(int i=0;i<T[cen].size();i++){
       pair<int,int> a =T[cen][i];
       st[a.st]--;
    }
};
void solve(int n ){ //rozwiazuje w jednym kroku
   bool  er=0;
while(!er){
    er=1;
    helper(n,0);
    vector<int> centry;

    for(int i=1;i<=n;i++){
        if(!czarny[i] and !odw[i]){int a=centroid(n,i);if(a>0){centry.push_back(a);er=0;} ; };
    }
    helper(n,1);
    for(int y:centry){
        licz(n,y);
    };
    helper(n,1);
    helper(n,3);//czyszcze cen_odl
}


//for(int i=0;i<centry.size();i++)
//cout<<centry[i];


}

void read(int n){
for(int i=1;i<=n;i++){
        cin>>L[i];
    };
    for(int i=1;i<=n-1;i++){
        int a,b,d;
        cin>>a>>b>>d;
        T[a].push_back(pair<int,int>(b,d) );
        T[b].push_back(pair<int,int>(a,d) );
        st[a]++;
        st[b]++;
    }
return;
}
