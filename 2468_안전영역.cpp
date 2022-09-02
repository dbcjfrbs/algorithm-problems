#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int n, ans=1;
int map[100][100], visit[100][100], height[101];
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
	
void bfs(int x, int y, int h){
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	visit[x][y]=1;

	pair<int, int> t;
	while(!q.empty()){
		t=q.front();
		q.pop();
		
		int nx, ny;
		for(int i=0; i<4; i++){
			nx=t.first+dx[i]; ny=t.second+dy[i];
			if(0<=nx && nx<n && 0<=ny && ny<n && !visit[nx][ny] && map[nx][ny]>h){
				q.push({nx, ny});
				visit[nx][ny]=1;
			}				
		}	
	}	
	
	return ;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> map[i][j];
			height[map[i][j]]++;
		}
	}	

	for(int i=1; i<100; i++){
		if(!height[i]) continue;

		memset(visit, 0, sizeof(visit));
		int cnt=0;
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				if(!visit[j][k] && map[j][k]>i){
					bfs(j, k, i);
					cnt++;
				}
			}
		}
		if(ans<cnt) ans=cnt;
	}			
	cout << ans;
	
	return 0;
}
