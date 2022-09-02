#include <iostream>
using namespace std;

int n;
int map[4][500];

long long ans=0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n;
	for(int i=0; i<n; i++){
		for(int i=0; i<4; i++){
			cin >> map[i][j];
		}
	}    
	
	
	   
    return 0;
}
