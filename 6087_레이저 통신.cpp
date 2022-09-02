#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321
typedef long long ll;
using namespace std;

int r, c, ans;
string map[101];
vector<vector<int> > raser;
bool visit[100][100];
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

void init(){
	cin >> c >> r;
	for(int i=0; i<r; i++){
		cin >> map[i];
		for(int j=0; j<c; j++){
			if(map[i][j]=='C') raser.push_back({i, j});
		}
	}
	return ;
}

void go(int x, int y, int dir, queue<vector<int> > &q){
	while(0<=x && x<r && 0<=y && y<c && map[x][y]!='*'){
		if(visit[x][y]){
			x+=dx[dir];	y+=dy[dir];
			continue;		
		}

		q.push({x, y});
		visit[x][y]=true;
		
		x+=dx[dir];	y+=dy[dir];
	}
	return ;
}

void bfs(int x, int y){
	queue<vector<int> > q;
	q.push({x, y});
	visit[x][y]=true;
	
	while(!q.empty()){
		int q_size=q.size();
		while(q_size--){
			int tx=q.front()[0], ty=q.front()[1];
			q.pop();
			
			for(int i=0; i<4; i++){
				int nx=tx+dx[i], ny=ty+dy[i];	
				go(nx, ny, i, q);
			}
		}
		
		if(visit[raser[1][0]][raser[1][1]]) break;
		ans++;
	}
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();
		
	bfs(raser[0][0], raser[0][1]);
		
	cout << ans;
	return 0;
}
