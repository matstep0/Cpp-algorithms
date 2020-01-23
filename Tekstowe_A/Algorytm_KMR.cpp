//szukam najmniejszej liczby k dla której nie dwóch takich samych fragmentów o dł k
#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second
typedef  pair< pair<int,int> , int>  triple ; //para oraz index
vector< int > slownik[16];  //vektor w ktorym sa wektory nr ow slow(leksykograficzny) o dlugosi 2doi
void kontrol(vector<int> planeta){
 for(int i=0;i<planeta.size();i++)
cout<<planeta[i];
cout<<endl;
}

void tworz(int w,int k){  //k oznacza potege dwojki w oznacza wskaznik na wektor aktualny slownik

vector<triple> trojki;
    for(int i=0;i+k<slownik[w-1].size();i++){  //tworzy pary
    triple d;
    d.st.nd=slownik[w-1][i+k]; //bo pary maja byc odwrotnie coby sortowal najpierw po "durgiej wartosci
    d.st.st=slownik[w-1][i];
    d.nd=i;  //index
    trojki.push_back(d);
    }
  sort(trojki.begin(),trojki.end());
  vector<int> wypluj(trojki.size() ); //wektor z nr slow o dlugosci 2 do k
    int nr=0;
    for(int i =0 ;i<trojki.size();i++){  //wpisuje nr par do wypluj
    wypluj[trojki[i].nd]=nr;
    if(i+1<trojki.size() and trojki[i].st != trojki[i+1].st)nr++;
    }
    swap(wypluj,slownik[w]);
    return ;
}

bool czy(int ile,int k,int s){
vector<triple> trojki;

    for(int i=0;i+s-k<slownik[ile].size();i++){  //tworzy pary
    triple d;
    d.st.nd=slownik[ile][i+s-k];
    d.st.st=slownik[ile][i];
    d.nd=i;  //index
    trojki.push_back(d);
    }
  sort(trojki.begin(),trojki.end());
    for(int i =0 ;i+1<trojki.size();i++)  //wpisuje nr par do wypluj
    if (trojki[i].st == trojki[i+1].st)return true; //jeden oznacza ze jest powtorzenie

return false;
}

int binsearch(int p,int q){ //szukam najmniejszej k takie że nie ma dwóch takich samych fragmnetów

int s=(p+q)/2;  //s dlugosc slowa
if(p>=q)return s;
  //k oznacza potege dwojki w oznacza wskaznik na wektor aktualny slownik
  int ile=0,k=1;  //ile razy musze podniesc 2 do potegi zeby wyszlo <s
  while(k*2<s)
  {ile++;k*=2;
  }

    if( czy(ile,k,s) )return binsearch(s+1,q);
    else
    return binsearch(p,s);
}


main(){
ios_base::sync_with_stdio (false);
int Z;
cin>>Z;
while(Z--){
int n;
cin>>n;
vector<int> planeta (0);
for(int i=0;i<n;i++){
int dow;
cin>>dow;
planeta.push_back(dow);
}
int ile=1; //ile do potegi dwojki
while(ile<planeta.size())
ile*=2;

for(int i=planeta.size();i<ile;i++ ){
planeta.push_back(-i);
}


slownik[0]=planeta;


for(int k=1,w=1;k<planeta.size();k*=2, w++ )
tworz(w,k) ;


cout<<binsearch(1,planeta.size())<<endl;


}

return 0;
}
