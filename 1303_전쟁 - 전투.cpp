#include <iostream>
#define MAX 101
using namespace std;

int n, m;
int visit[MAX][MAX];
char map[MAX][MAX];
struct POINT{
	int x, y;
};
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

int bfs(int x, int y){
	POINT q[10000];
	int f=-1, r=-1;
	
	visit[x][y]=1;
	q[++r]={x, y};

	int cnt=1;
	while(f!=r){
		int tx=q[++f].x, ty=q[f].y;
		for(int i=0; i<4; i++){
			int nx=tx+dx[i], ny=ty+dy[i];
			if(0>nx || nx>=m || ny<0 || ny>=n || visit[nx][ny]==1 || map[nx][ny]!=map[x][y]) continue;
			
			q[++r]={nx, ny};
			visit[nx][ny]=1;
			cnt++;
		}		
	}
	
	return cnt*cnt;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> map[i];
	}
	
	int white=0, blue=0;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(visit[i][j]==1) continue;
			
			if(map[i][j]=='W') white+=bfs(i, j);
			else blue+=bfs(i, j);
		}
	}
	
	cout << white << ' ' << blue;
	
	return 0;
} 
