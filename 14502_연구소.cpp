#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int n, m, ans, walls, map[10][10];
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
vector<vector<int> > v, virus;
bool visit[10][10], visit2[10][10];

void init(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> map[i][j];
			
			if(map[i][j]==0) v.push_back({i, j});
			else if(map[i][j]==1){
				visit[i][j]=true;
				walls++;
			}
			else virus.push_back({i, j});
		}
	}
	return ;
}

int bfs(int x, int y){
	int ret=1;
	queue<vector<int> > q;
	q.push({x, y});
	visit2[x][y]=true;
	
	while(!q.empty()){
		int tx=q.front()[0], ty=q.front()[1];
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx=tx+dx[i], ny=ty+dy[i];
			if(nx<0 || n<=nx || ny<0 || m<=ny || visit[nx][ny] || visit2[nx][ny] || map[nx][ny]==2) continue;
			
			q.push({nx, ny});
			visit2[nx][ny]=true;
			ret++;
		}
	}
	
	return ret; 
}

void countRoom(){
	int virus_size=virus.size(), virus_cnt=0;
	for(int i=0; i<virus_size; i++){
		int x=virus[i][0], y=virus[i][1];
		virus_cnt+=bfs(x, y);
	}	
	 
	int room=n*m-virus_cnt-walls-3;
	if(ans<room) ans=room;
	
	return ;
}

void comb(int depth, int start, int size){
	if(depth==3){
		countRoom();		
		memset(visit2, 0, sizeof(visit2));
		
		return ;
	}
	
	for(int i=start; i<size-3+depth+1; i++){
		int x=v[i][0], y=v[i][1];
		visit[x][y]=true; // 벽세우기
		comb(depth+1, i+1, size);  
		visit[x][y]=false; //벽빼기
	}	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();

	comb(0, 0, v.size());
	
	cout << ans;
	
	return 0;
}
