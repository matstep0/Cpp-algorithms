//backtrack
#include<bits/stdc++.h>
using namespace std;
string P[12];//plansza od 1 do 10 //rzad kolumna //14 na 14 dwa zapasu

int f(int x,int y,int xv, int yv);
int backtrack(int x,int y);

int f(int x,int y,int xv, int yv){
int a=0;
    if(P[x+xv][y+yv]=='B' and P[x+2*xv][y+2*yv]=='.' ){
        P[x+xv][y+yv]='.';
        P[x+2*xv][y+2*yv]='W';
        P[x][y]='.';
        a=backtrack(x+2*xv,y+2*yv)+1;
        P[x+xv][y+yv]='B';
        P[x+2*xv][y+2*yv]='.';
        P[x][y]='W';
    };
return a;
};

int backtrack(int x,int y){ //pozycje pionka
int a=f(x,y,-1,-1);
int b=f(x,y,-1,+1);
int c=f(x,y,+1,-1);
int d=f(x,y,+1,+1);

int w=max(max(a,b),max(c,d));

return w;
}

int main(){
ios_base::sync_with_stdio(false);
int Z;
cin>>Z;
while(Z--){
    P[0]="@@@@@@@@@@@@";
    for(int i=1;i<=10;i++){
     string S="@";
     string a;
     cin>>a;
     for(int i=0;i<a.size();i++)if(a[i]=='#')a[i]='.';
     S+=a;
     S+="@";
     P[i]=S;
    };
    P[11]="@@@@@@@@@@@@";
    int wynik=0;
    for(int i=1;i<=10;i++)
     for(int j=1;j<=10;j++)
      if(P[i][j]=='W'){
        int o=backtrack(i,j);
        wynik=max(wynik,o);
      };
    cout<<wynik<<"\n";
}


return 0;
}
