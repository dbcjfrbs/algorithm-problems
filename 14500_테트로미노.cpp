#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, map[500][500], ans;
bool visit[500][500];
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

void init(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> map[i][j];
	}	
	return ;
}

void dfs(int x, int y, int sum, int depth){	
	if(depth==4){
		if(ans<sum) ans=sum;
		return ;
	}

	sum+=map[x][y];

	visit[x][y]=true;
	for(int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if(nx<0 || n<=nx || ny<0 || m<=ny || visit[nx][ny]) continue;
		dfs(nx, ny, sum, depth+1);
	}
	visit[x][y]=false;
	
	return ;
}

void exceptionCase(int x, int y){
	int flag=0, sum=map[x][y];
	for(int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if(nx<0 || n<=nx || ny<0 || m<=ny) continue;
		
		sum+=map[nx][ny];
		flag++;				
	}
	
	if(flag<3){
		return ;
	}
	else if(flag==3){
		if(ans<sum) ans=sum; // Áß¿ä 
	}
	else if(flag==4){
		for(int i=0; i<4; i++){
			int nx=x+dx[i], ny=y+dy[i];
			if(ans<sum-map[nx][ny]) ans=sum-map[nx][ny];
		}	
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
			dfs(i, j, 0, 0);
			exceptionCase(i, j);
		}
	}	
	
	cout << ans;
	return 0;
}
