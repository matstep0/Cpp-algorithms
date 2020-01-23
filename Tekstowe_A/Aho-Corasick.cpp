//A8 Aho Corasik Automat skończony czy da się zrobić ciag żeby nie było w nich wzorow
#include<bits/stdc++.h>

using namespace std;
const int roz=1050000;
int przejscie[roz][2];
int fail[roz];
bool wzorzec[roz]; //czy lisc i jest wzorem albo jego fail jest

enum kolor{
czarny = 2 , //odw hardo
szary = 1 ,
bialy = 0
};
kolor odw[roz];

void wypelnij(int n){ //wypelnia tablice wyzej -1
    for(int i=0;i<n+2;i++){
        przejscie[i][0]=-1;
        przejscie[i][1]=-1;
        fail[i]=-1;
        wzorzec[i]=false;
        odw[i]=bialy;
    }
return;
}

int trie(vector<string> & wirusy){
int nr=1;
    for(int i=0;i<wirusy.size();i++)
    {//1
        int gdzie=0; //w ktorym wierzcholku jestem
        for(int j=0;j<wirusy[i].size();j++)
        {//2
            int a=int(wirusy[i][j]-'0');
            if(przejscie[gdzie][a]==-1)
            {//3
                przejscie[gdzie][a]=nr;
                nr++;
            }//3
            gdzie=przejscie[gdzie][a];
        }//2
        wzorzec[gdzie]=true;

    }//1
return nr-1; //numer ostatniego wierzcholka
}



void failuj(){
fail[0]=0;
queue<int> kolejka;
if(przejscie[0][0]!=-1){fail[przejscie[0][0]]=0;kolejka.push(przejscie[0][0]);}
if(przejscie[0][1]!=-1){fail[przejscie[0][1]]=0;kolejka.push(przejscie[0][1]);}
//BFS
while(!kolejka.empty()){
    int wie=kolejka.front();
    kolejka.pop();
    if(wzorzec[fail[wie]]==true)wzorzec[wie]=true; //Uwaga niebezpieczne
    if(przejscie[wie][0]!=-1)
    {
        int y=przejscie[wie][0];
        kolejka.push(y);
        int s=fail[wie];
        while(s>0 and przejscie[s][0]==-1)
            s=fail[s];
        if(przejscie[s][0]!=-1)
            fail[y]=przejscie[s][0];
        else
            fail[y]=0;
    }
    if(przejscie[wie][1]!=-1)
    {
        int y=przejscie[wie][1];
        kolejka.push(y);
        int s=fail[wie];
        while(s>0 and przejscie[s][1]==-1)
            s=fail[s];
        if(przejscie[s][1]!=-1)
            fail[y]=przejscie[s][1];
        else
            fail[y]=0;
    }

}



}
void strzalki(){
   queue<int>kolejka;
   kolejka.push(0);
   while(!kolejka.empty()){
        int wie=kolejka.front();
        kolejka.pop();
        if(przejscie[wie][0]!=-1)
            kolejka.push(przejscie[wie][0]);
        else
            przejscie[wie][0]=przejscie[fail[wie]][0];

        if(przejscie[wie][1]!=-1)
            kolejka.push(przejscie[wie][1]);
        else
            przejscie[wie][1]=przejscie[fail[wie]][1];
   }
}
bool DFS(int wie){
odw[wie]=szary;
int y=przejscie[wie][0];
if(odw[y]==szary)return true;
if(odw[y]==bialy)if( DFS(y) )return true;

y=przejscie[wie][1];
if(odw[y]==szary)return true;
if(odw[y]==bialy)if( DFS(y) )return true;

odw[wie]=czarny;
return false;
}

bool cykl(int dl){
for(int i=0;i<dl;i++)
    if(wzorzec[i]==true)odw[i]=czarny;
//DFS
return DFS(0);

}
int main(){
int Z;
cin>>Z;
while(Z--){
int w;//ile wzorcow
cin>>w;
vector<string> wirusy(w);
int dl=0;
for(int i=0;i<w;i++){
    cin>>wirusy[i];
     dl+=wirusy[i].size();
}
wypelnij(dl+5);
trie(wirusy);
failuj();
strzalki();
bool TAK=cykl(dl);
if(TAK)cout<<"TAK"<<endl;
else
cout<<"NIE"<<endl;
}
return 0;
}
