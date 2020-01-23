#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>

#define PI pair<int,int>
#define MP make_pair

using namespace std;

const int M = 200*1000;

int A[M+1],P[M+1];
bool on[M+1];

int main()
{
  int seed,TT,maxn,d,maxq,maxcount;
  scanf("%d%d%d%d%d%d",&seed,&TT,&maxn,&d,&maxq,&maxcount);
  srand(seed);
  printf("%d\n",TT);
  while(TT--)
  {
    vector<PI> edges;
    int n = random()%(maxn/4)+(3*maxn/4);
    for(int i=0; i<n; i++)
      A[i] = i+1;
    random_shuffle(A,A+n);
    for(int i=1; i<n; i++)
      P[i] = i - std::min((long)i,random()%d+1);
    printf("%d\n",n);
    for(int i=1; i<n; i++)
    {
      edges.push_back(MP(A[i],A[P[i]]));
      if (random()%2)
        swap(edges[i-1].first,edges[i-1].second);
    }
    random_shuffle(edges.begin(),edges.end());
    for(int i=0; i<n-1; i++)
      printf("%d %d\n",edges[i].first, edges[i].second);
    int q = random()%(maxq/4)+(3*maxq/4);
    printf("%d\n",q);
    for(int i=0; i<n; i++)
      on[i] = true;
    vector<int> D;
    for(int i=0; i<q; i++)
    {
       if (random()%10==0)
       {
         if (D.size()<maxcount)
         {
           int k;
           do
             k = random()%n;
           while(!on[k]);
           printf("- %d\n",A[k]);
           on[k] = false;
           D.push_back(k);
         } else
         {
           int k = random()%D.size();
           printf("+ %d\n",A[D[k]]);
           on[D[k]] = true;
           swap(D[k],D[D.size()-1]);
           D.pop_back();
         }
       } else
       printf("? %d %d\n",random()%n+1,random()%n+1);
    }
  }
}