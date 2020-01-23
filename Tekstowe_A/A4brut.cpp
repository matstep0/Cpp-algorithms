#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<int> A;
bool repetition;
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    int Z;
    cin >> Z;
    while (Z--)
    {
        repetition = false;
        cin >> n;
        A = vector<int> (n+1, 0);
        for (int i = 0; i < n; i++)
            cin >> A[i];
            A[n]=-1;
n++;
for(int i=0;i+1<n;i++)
if(A[i]==A[i+1]){repetition=true;goto W;}

        for (int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){
                int k=0;
                while(A[i+k]==A[j+k]){
                    k++;
                    if(i+k==j){repetition = true;goto W;}
                    }

        }

        W:
        if (repetition)
            cout << "TAK" << endl;
        else
            cout << "NIE" << endl;
    }
}
