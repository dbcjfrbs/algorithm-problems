#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321
using namespace std;

int n, l, r, map[50][50], ans, visit[50][50], cnt;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

void init(){
	cin >> n >> l >> r;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) cin >> map[i][j];
	} 
	return ;
}

void update(int sum, int room_cnt, queue<vector<int> > &q_){
	int val=sum/room_cnt;
	while(!q_.empty()){
		int x=q_.front()[0], y=q_.front()[1];
		q_.pop();
		
		map[x][y]=val;
	}

	return ;	
}

void bfs(int x, int y){
	queue<vector<int> > q, q_;
	q.push({x, y});
	q_.push({x, y});
	visit[x][y]=++cnt;
	
	int sum=map[x][y], room_cnt=1;
	while(!q.empty()){
		int tx=q.front()[0], ty=q.front()[1];
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx=tx+dx[i], ny=ty+dy[i];
			if(nx<0 || n<=nx || ny<0 || n<=ny || visit[nx][ny]!=0) continue;
			
			int dif=abs(map[tx][ty]-map[nx][ny]);
			if(dif<l || r<dif) continue;
			
			q.push({nx, ny});
			q_.push({nx, ny});
			visit[nx][ny]=visit[tx][ty];

			sum+=map[nx][ny];
			room_cnt++;
		}
	}

	update(sum, room_cnt, q_);
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();
	
	while(1){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(visit[i][j]!=0) continue;
				bfs(i, j);
			}
		}

		if(cnt==n*n) break;	
		ans++;
// 초기화 부분 
		memset(visit, 0, sizeof(visit));
		cnt=0;
	}
	
	cout << ans;	
	return 0;
}
