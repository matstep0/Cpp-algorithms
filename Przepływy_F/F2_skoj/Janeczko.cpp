#include <bits/stdc++.h>
using namespace std;

bool ldfs(int u, vector <int> &M, vector <bool> &Vis, vector < vector <int> > &Neigh)
{
    if(Vis[u])
        return false;
    Vis[u]=true;
    for(int i=0; i<Neigh[u].size(); i++)
        if(M[Neigh[u][i]]==-1 || ldfs(M[Neigh[u][i]],M,Vis,Neigh))
            {
                M[u]=Neigh[u][i];
                M[Neigh[u][i]]=u;
                return true;
            }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int z;
    cin >> z;
    for(int o=1; o<=z; o++)
        {
            int n1, n2, m;
            cin >> n1 >> n2 >> m;
            int n=n1+n2;
            vector < vector <int> > Neigh(n);
            vector <int> M(n,-1);
            vector <bool> Vis(n);
            for(int i=0; i<m; i++)
                {
                    int a, b;
                    cin >> a >> b;
                    a--; b--;
                    Neigh[a].push_back(b+n1);
                    Neigh[b+n1].push_back(a);
                }
            bool inc=true;
            while(inc)
                {
                    for(int i=0; i<n; i++)
                        Vis[i]=false;
                    inc=false;
                    for(int u=0; u<n; u++)
                        if(M[u]==-1 && ldfs(u,M,Vis,Neigh))
                            inc=true;
                }
            int wynik=0;
            for(int i=0; i<n; i++)
                if(M[i]!=-1)
                    wynik++;
            wynik/=2;
            cout << wynik <<endl;
        }
    return 0;
}
