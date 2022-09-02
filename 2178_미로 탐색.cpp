#include <iostream>
using namespace std;

int n, m;
char map[101][101];
int visited[100][100]={0};

bool isWall(int x, int y){
	if(x<0 || x>=n || y<0 || y>=m) return 1;
	return 0;
}

void bfs(){ // 인자 왜 안되는지 다시 보기
	int qx[n*m], qy[n*m];
	int f=-1, r=-1;
	int dx[4]={1, 0, -1, 0};
	int dy[4]={0, 1, 0, -1};
	
	qx[++r]=0; qy[r]=0;
	visited[0][0]=1;
	while(f!=r){
		int tx=qx[++f]; int ty=qy[f];

		for(int i=0; i<4; i++){
			int nx=tx+dx[i]; int ny=ty+dy[i];

			if(!isWall(nx, ny)){
				if(map[nx][ny]=='1' && visited[nx][ny]==0){
					qx[++r]=nx; qy[r]=ny;
					
					visited[nx][ny]=visited[tx][ty]+1;
				}
			}
		}
	}

	return ;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> map[i];
	}

	bfs();
	cout << visited[n-1][m-1];

	return 0;
}
