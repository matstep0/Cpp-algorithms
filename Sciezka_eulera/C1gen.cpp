#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
int main()
{
    unsigned int srad = (unsigned int)time(0);
    srand(srad);
    try
    {
        int z = 0;
        printf("2\n");
        while (z < 2) {
            int n = rand() % 12 + 2;
            vector<vector<bool> > G(n + 1, vector<bool> (n + 1, false));
            vector<pair<int, int> > E(0), AllE(0);
            for (int i = 2; i <= n; i++)
            {
                int x = rand() % (i - 1) + 1;
                if (rand() % 2)
                    E.push_back(pair<int, int> (i, x));
                else
                    E.push_back(pair<int, int> (x, i));
                G[x][i] = true;
                G[i][x] = true;
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (!G[j][i] && !G[i][j] && i != j)
                    {
                        if (rand() % 2)
                            AllE.push_back(pair<int, int> (i, j));
                        else
                            AllE.push_back(pair<int, int> (j, i));
                        G[i][j] = true;
                        G[j][i] = true;
                    }
                }
            }
            if (!AllE.empty())
            {
                int newM = rand() % AllE.size();
                for (int i = 0; i < newM && !AllE.empty(); i++)
                {
                    int r = rand() % AllE.size();
                    if (0 > r || r >= AllE.size())
                        break;
                    swap(AllE[r], AllE[AllE.size() - 1]);
                    E.push_back(AllE[AllE.size() - 1]);
                    AllE.pop_back();
                }
            }
            printf("%i %i\n", n, (int)E.size());
            while (!E.empty())
            {
                int r = rand() % E.size();
                swap(E[r], E[E.size() - 1]);
                printf("%i %i\n", E[E.size() - 1].first, E[E.size() - 1].second);
                E.pop_back();
            }
            printf("\n");
            z++;
        }
    }
    catch(int e)
    {
        ofstream myfile;
        myfile.open ("Gen_error.txt");
        myfile << srad << endl;
        myfile.close();
    }
}
