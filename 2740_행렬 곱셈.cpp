#include <iostream>
using namespace std;

int n, m, k, matrix1[100][100], matrix2[100][100];

void init(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> matrix1[i][j];
	}
	
	cin >> m >> k;
	for(int i=0; i<m; i++){
		for(int j=0; j<k; j++) cin >> matrix2[i][j];
	}
	return ;
}

int calc(int x, int y){
	int ret=0;
	for(int i=0; i<m; i++){
		ret+=matrix1[x][i]*matrix2[i][y];
	}
	return ret;
}

int main(){
	init();	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<k; j++){
			cout << calc(i, j) << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
