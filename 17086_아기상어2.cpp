#include <iostream>
#include <queue>
using namespace std;

int n, m, ans=1;
int map[50][50], visit[50][50];
int dx[8]={1, 1, 0, -1, -1, -1, 0, 1}, dy[8]={0, 1, 1, 1, 0, -1, -1, -1};

int bfs(int x, int y){
	int ret;
	queue<pair<int, int> > q;

	q.push({x, y});
	visit[x][y]=0;
	
	while(!q.empty()){
		int tx=q.front().first, ty=q.front().second;
		q.pop();
		
		for(int i=0; i<8; i++){
			int nx=tx+dx[i], ny=ty+dy[i];
			if(nx<0 || n<=nx || ny<0 || m<=ny || visit[nx][ny]!=-1) continue;
			if(map[nx][ny]==1) return ret=visit[tx][ty]+1;
			
			q.push({nx, ny});
			visit[nx][ny]=visit[tx][ty]+1;
		}
	}
}

void init(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) visit[i][j]=-1;
	}

	return ;	
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> map[i][j];
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(map[i][j]==1) continue;
			init();
			
			int tmp=bfs(i, j);
			if(ans<tmp) ans=tmp;
		}
	}
	
	cout << ans;

	return 0;
}
