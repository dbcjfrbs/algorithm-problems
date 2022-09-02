#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[200][200];

queue<pair<int, int> > q;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

void bfs(){
	while(!q.empty()){
		int x=q.front().first, y=q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx=x+dx[i], ny=y+dy[i];
			if(nx<0 || n<=nx || ny<0 || m<=ny || map[nx][ny]!=0) continue;

			map[nx][ny]=map[x][y]+1;
			q.push({nx, ny}); 
		}
	}
	
	return ;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
//		cin >> map[i]; // 이게 근데 왜 되는거지?
		for(int j=0; j<m; j++){
			char c=cin.get();
			if(c=='\n') map[i][j]=cin.get()-'0';
			else map[i][j]=c-'0';
			
			if(map[i][j]==1) q.push({i, j});
		}
	}
	
	bfs();
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << map[i][j]-1 << ' ';
		}
		cout << endl;
	}
	
	return 0;
}
