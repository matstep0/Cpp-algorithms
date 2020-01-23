#include <iostream>
#include <random>
using namespace std;
int main(){
	random_device rd;
	srand(rd());
	int z = 20;
	cout << z << endl;
	for(int w = 0; w < z; w++){
		int n = 300;
		for(int i = 0; i < n; i++){
			char t = 65+rand()%10;
			cout << t;
		}
		cout << endl;
	}
}
