#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, ans;
char map[50][51];
bool visit[50][50];

void init(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> map[i];
	}	
	return ;
}

void check(int x, int y){	
	if(map[x][y]=='-'){
		while(y<m && map[x][y]=='-') visit[x][y++]=true;
	}
	else{
		while(x<n && map[x][y]=='|') visit[x++][y]=true;
	}
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(visit[i][j]) continue;
			check(i, j);
			ans++;
		}
	}	
	
	cout << ans;		
	return 0;
}
