#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int n, m, map[1000][1000], d[1000][1000];
int dx[3]={1, 0, 1}, dy[3]={0, 1, 1};

void init(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> map[i][j];
			d[i][j]=map[i][j];
		}
	}
	return ;
}

//void dfs(int x, int y, bool visit[][1000], int sum){ // 인자 설정 시 const로? 
//	visit[x][y]=true;
//	
//	for(int i=0; i<2; i++){
//		int nx=x+dx[i], ny=y+dy[i];
//		if(nx<0 || n<=nx || ny<0 || m<=ny) continue;
//		if(sum+map[nx][ny]<=d[nx][ny] || visit[nx][ny]) continue;
//
//		d[nx][ny]=sum+map[nx][ny];
//		dfs(nx, ny, visit, d[nx][ny]);		
//	}
//	visit[x][y]=false;
//		
//	return ;
//}

//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);	
//
//	init();
//	bool visit[n][1000]={0,};
//	dfs(0, 0, visit, map[0][0]);
//	
//	cout << d[n-1][m-1];
//	
//	return 0;
//}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();
	
	for(int i=0; i<n+m-1; i++){
		for(int j=0; j<=i; j++){
			int x=j, y=i-j;
			if(x>=n || y>=m) continue;
			
			for(int i=0; i<=1; i++){
				int nx=x+dx[i], ny=y+dy[i];
				if(nx>=n || ny>=m) continue;
				if(map[nx][ny]+d[x][y]<=d[nx][ny]) continue;
				d[nx][ny]=map[nx][ny]+d[x][y];
			}
		}
	}
	
	cout << d[n-1][m-1];
	
	return 0;
}
