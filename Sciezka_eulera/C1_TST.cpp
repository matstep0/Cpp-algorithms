#include <iostream>
#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

bool spr()
{
    try
    {
        ifstream file;
        ifstream answer;
        answer.open("0.my");
        file.open("0.in", ios_base::in);
        vector<vector<bool> > Graph, AnsGraph;
        if (file.is_open() && answer.is_open())
        {
            int Z;
            file >> Z;
            for (int z2 = 0; z2 < Z; z2++)
            {
                //printf("Start test: %i\n", z2);
                int n, m;
                file >> n >> m;
                Graph = vector<vector<bool> > (n + 1, vector<bool> (n + 1, false));
                AnsGraph = Graph;
                for (int i = 0; i < m; i++)
                {
                    int a, b;
                    file >> a >> b;
                    Graph[a][b] = true;
                    Graph[b][a] = true;
                }
                //printf("Read Graph\n");
                int lines;
                answer >> lines;
                for (int i = 0; i < lines; i++)
                {
                    int d, a, b;
                    answer >> d;
                    if (d < 2)
                    {
                        printf("test: %i; Line(%i), wrong distance;\n", z2, i);
                        file.close();
                        answer.close();
                        return false;
                    }
                    answer >> a;
                    for (int j = 1; j < d; j++)
                    {
                        answer >> b;
                        if (AnsGraph[a][b] || AnsGraph[b][a])
                        {
                            printf("test: %i; Line(%i), used edge (%i; %i)\n", z2, i, a, b);
                            file.close();
                            answer.close();
                            return false;
                        }
                        if (!Graph[a][b] || !Graph[b][a])
                        {
                            printf("test: %i; Line(%i), no edge (%i; %i)\n", z2, i, a, b);
                            file.close();
                            answer.close();
                            return false;
                        }
                        AnsGraph[a][b] = true;
                        AnsGraph[b][a] = true;
                        a = b;
                    }
                }
                //printf("Read Lines\n");
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        if (Graph[i][j] && !AnsGraph[i][j])
                        {
                            printf("test: %i; have not used edge (%i; %i)\n", z2, i, j);
                            file.close();
                            answer.close();
                            return false;
                        }
                    }
                }
                //printf("Compared Graphs\n");
                //printf("End test: %i\n", z2);
            }
        }
        else
        {
            printf("ERROR::READ\n");
            return false;
        }
        file.close();
        answer.close();
        return true;
    } catch (int e) {
        ofstream myfile;
        myfile.open ("error.txt");
        myfile << "ERROR COMPARING" << endl;
        myfile.close();
        return false;
    }

}

using namespace std;
int main()
{
    int i = 0;
    while (i < 1000000000)
    {
        i++;
        try {
            system("./C1gen > 0.in");
            system("./Euler_deb/main < 0.in > 0.my");
        } catch (int e) {
            printf("Error tst\n");
        }

        if (spr())
            printf("OK %i\n", i);
        else
        {
            printf("ANS\n");
            break;
        }
    }
}
