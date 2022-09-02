#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321
using namespace std;

int tc, n, sx, sy, r;
bool visit[5001][5001]; 
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

void dfs(int x, int y, int depth){
	if(depth==r+1) return ;	
	visit[x][y]=true;
	
	for(int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if(nx<0 || 5000<nx || ny<0 || 5000<ny || visit[nx][ny]) continue;
		
		dfs(nx, ny, depth+1);
	}	
	
	return ;
}

void bfs(int x, int y){
	queue<vector<int> > qq;
	qq.push({x, y});
	visit[x][y]=false;
	
	while(!qq.empty()){
		int tx=qq.front()[0], ty=qq.front()[1];
		qq.pop();	
		
		for(int i=0; i<4; i++){
			int nx=tx+dx[i], ny=ty+dy[i];
			if(nx<0 || 5000<nx || ny<0 || 5000<ny || visit[nx][ny]==false) continue;
			
			visit[nx][ny]=false;
			qq.push({nx, ny});
		}
	}
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	cin >> tc;
	while(tc--){
		cin >> n;
		int tmp=n;
		queue<vector<int> > q;
		while(tmp--){
			cin >> sx >> sy >> r;
	
			dfs(sx, sy, 0);
			q.push({sx, sy});
		}
		
		int ans=0;
		while(!q.empty()){
			int x=q.front()[0], y=q.front()[1];
			q.pop();
			
			if(visit[x][y]){
				ans++;
				bfs(x, y);
			}
		}
		
		memset(visit, 0, sizeof(visit));		
		cout << ans << '\n';
	}

	return 0;
}
