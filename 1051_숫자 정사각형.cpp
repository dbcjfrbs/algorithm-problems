#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m, ans=1, max_size;
char map[50][51];
int dx[4]={1, 1, 0, 0}, dy[4]={0, 1, 0, 1};

void init(){
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> map[i];
}

int maxSquare(int x, int y){
	int ret=1;
	char val=map[x][y];
	for(int i=1; i<max_size; i++){
		for(int j=0; j<4; j++){
			int nx=x+dx[j]*i, ny=y+dy[j]*i;
			if(n<=nx || m<=ny || map[nx][ny]!=val) break;			
			if(j==3) ret=(i+1)*(i+1);
		}
	}
	
	return ret;
}

int main(){
	init();
	
	max_size=min(m, n);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int tmp=maxSquare(i, j);
			if(ans<tmp) ans=tmp;
		}
	}	
	
	cout << ans;	
	return 0;
}
