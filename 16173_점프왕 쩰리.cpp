#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, map[3][3];
bool visit[3][3];
int dx[2]={1, 0}, dy[2]={0, 1};
string ans="Hing";

void dfs(int x, int y){ //0, 1
	if(x==n-1 && y==n-1){
		ans="HaruHaru";
		return ;
	}
	visit[x][y]=true;
		
	for(int i=0; i<2; i++){
		int nx=x+dx[i]*map[x][y], ny=y+dy[i]*map[x][y];
		if(nx<n && ny<n && visit[nx][ny])==false) dfs(nx, ny);
	}
	
	return ;
}

void dfs(int x, int y){ //0, 2
	if(x==n-1 && y==n-1){
		ans="HaruHaru";
		return ;
	}
	visit[x][y]=true;
		
	for(int i=0; i<2; i++){
		int nx=x+dx[i]*map[x][y], ny=y+dy[i]*map[x][y];
		if(nx<n && ny<n && visit[nx][ny])==false) dfs(nx, ny);
	}
	
	return ;
}


int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) cin >> map[i][j];
	}

	dfs(0, 0);

	cout << ans;	
	return 0;
}
