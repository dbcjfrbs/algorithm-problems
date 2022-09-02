#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
char map[7000][7000];

void solve(int x, int y, int n){
	int sx=x+n/3, ex=x+n/3*2, sy=y+n/3, ey=y+n/3*2;
	for(int i=sx; i<ex; i++){
		for(int j=sy; j<ey; j++){
			map[i][j]=' ';
		}
	}

	if(n==3) return ;
	for(int i=x; i<x+n; i+=n/3){
		for(int j=y; j<y+n; j+=n/3){
			if(i==sx && j==sy) continue;
			solve(i, j, n/3);
		}
	}

	return ;
}

int main(){
	int n;
	cin >> n;
	memset(map, '*', sizeof(map));

	solve(0, 0, n);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << map[i][j];
		}
		cout << endl;
	}
		
	return 0;
}
