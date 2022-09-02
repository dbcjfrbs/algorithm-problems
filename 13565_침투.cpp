#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
char map[1000][1001];
bool visit[1000][1000]; 
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

void init(){
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> map[i];
	return ;
}

bool bfs(int x, int y){
	queue<pair<int, int> > q;
	q.push({x, y});
		
	while(!q.empty()){
		int tx=q.front().first, ty=q.front().second;
		q.pop();
		
		if(tx==n-1) return true;
		
		for(int i=0; i<4; i++){
			int nx=tx+dx[i], ny=ty+dy[i];
			if(nx<0 || n<=nx || ny<0 || m<=ny || map[nx][ny]=='1' || visit[nx][ny]) continue;
			q.push({nx, ny});
			visit[nx][ny]=true;
		}
	} 
	
	return false;
}

int main(){
	init();
	for(int i=0; i<n; i++){
		if(map[0][i]=='1') continue;
		if(bfs(0, i)){
			cout << "YES";
			return 0;
		}
	}	
	
	cout << "NO";
	return 0;
}
