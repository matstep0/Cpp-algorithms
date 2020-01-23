#include<bits/stdc++.h>
using namespace std;
 char Slowo[2000005];
int P[2000005] = {0};
int k;
 //najwiekszy promien palindromiczny
            //wyczyść?
        //index elementu o najdalej siegajacym pronieniu
main(){
int Z;
cin>>Z;
    while(Z--){
        string S="!";
        string wejscie;
        cin>>wejscie;
        S+=wejscie;
        S+="?";

        int hasz=0; // do montowania haszow;

            for(int i=0;i<S.size();i++){
                Slowo[hasz+i]=S[i];
                hasz++;
                Slowo[hasz+i]='#';
            };
        int Size=S.size()*2;
       //zmienne sa globalne
       P[0]=0;  P[1]=0;
       k=1;
            for(int i=2;i<Size;i++){
             P[i]=0;
                if(k+P[k]>i){
                    int j=k-(i-k);
                    P[i]=min(P[j],k+P[k]-i);
                }
            while( Slowo[i+P[i]+1 ] == Slowo[i-P[i]-1])
                P[i]++;
                if(i+P[i] > k+P[k] )k=i;
            }
/*
        for(int i=0;i<Size;i++)
        cout<<Slowo[i];
        cout<<endl;
        for(int i=0;i<Size;i++){
        cout<<P[i]<<" ";
        };
        cout<<endl;
*/
//problem is solve //time for query
        int q;
        cin>>q;
            for(int i=0;i<q;i++){
                int a,b;
                cin>>a>>b;
                a*=2;b*=2;
                int s=(a+b)/2;
                        if(P[s]>=s-a)cout<<"TAK"<<endl;
                        else
                        cout<<"NIE"<<endl;
            }

    }//WHILE






return 0;
}
