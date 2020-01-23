//zadanie z wykorzystanie cyklu Eulera
#include<bits/stdc++.h>
using namespace std;
#define sasiad first
#define od second
vector< pair<int,int> > T[50*1000+5]; //tablica na graf druga wrtosci oznacza miejsce w tablicy booli przej
bool przej[500*1000+5]; //kazda krawdedz ma przypisany numer w tablicy bool czy przez nia przechodzilismy
int ost_in[50*1000+5]; //index dla wektora wskazujacy gdzie skonczylemsprawdzanie i bedzie indexem
int st[50*1000+5]; //stopien wejsca wierzcholka
//wierzcholek zerowy to moja pomoc do cyklowania
void clean(int n,int m){
    for(int i=0;i<=n+3;i++){
        T[i]=vector< pair<int,int> > ();

        ost_in[i]=0;
        st[i]=0;
    }
    for(int i=0;i<=n+m+2;i++){
        przej[i]=false;
    }
}
int main(){
ios_base::sync_with_stdio(false);
int Z;;

cin>>Z;
while(Z--){
int n,m;
cin>>n>>m;
for(int i=0;i<m; i++){
    int a,b;
    cin>>a>>b;
    T[a].push_back(make_pair(b,i));
    T[b].push_back(make_pair(a,i));
    st[a]++;
    st[b]++;
}
bool bzer=true;//zero nie ma krawedzi
for(int i=1;i<=n;i++)
if(st[i]%2==1){bzer=false;break;};

//read
    int ws = m; //do tablicy ost index
    for(int i=1;i<=n;i++){
        if(st[i]%2==1){
            T[0].push_back(make_pair(i,ws));
            T[i].push_back(make_pair(0,ws));
            ws++;
        }
    };
    //ALGORYTM
    vector<int> wynik;
    stack<int> cykl;//sluzy do wypisywania cyklo
    int wie=0; //wierzcholek w ktorym aktualnie jestem
    cykl.push(0);
    if(bzer){wie=1;cykl.pop();cykl.push(1);}

    do{
        wie=cykl.top();
        while(ost_in[wie]<T[wie].size() and przej[ T[wie][ ost_in[wie] ].od  ]==true )
            ost_in[wie]++;
        if(ost_in[wie]<T[wie].size()){
            cykl.push(T[wie][ost_in[wie]].sasiad);
            przej[T[wie][ost_in[wie]].od]=true;
            ost_in[wie]++;

        }
        else{
            wynik.push_back(cykl.top());

            cykl.pop();
            wie=cykl.top();
        }


    }while(!cykl.empty());
/*
for(int i=0;i<wynik.size();i++)
cout<<wynik[i]<<" ";
cout<<endl;
*/
if(bzer==1){
cout<<1<<" "<<endl;
cout<<wynik.size()<<" ";
for(int i=0;i<wynik.size();i++)
cout<<wynik[i]<<" ";
cout<<endl;
}
if(bzer==0){
int l=0;//liczba linii
for(int i=0;i<wynik.size();i++)
if(wynik[i]==0)l++;

l--;
cout<<l<<endl;
int kon=wynik.size()-2;
int ap=0; //ile jest wierzcholkow na linii
    while(kon>=0){
        if(wynik[kon]==0){wynik[kon]=-ap;kon--;ap=0;continue;}
        ap++;
        kon--;
    }


int id=0;
while(id<wynik.size()){
if(wynik[id]<0)cout<<abs(wynik[id])<<" ";
for(int i=0;i<abs(wynik[id]);i++)
cout<<wynik[id+i+1]<<" ";

cout<<endl;
id+=abs(wynik[id])+1;
}

}

clean(n,m);

}
return 0;
}
