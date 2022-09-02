#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321
using namespace std;

int n, map[20][20], cnt, ans, shark=2, sx, sy;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
vector<vector<int> > eatable;

bool compare(vector<int> a, vector<int> b){
	if(a[0]==b[0]) return a[1]<b[1]; 
	return a[0]<b[0];
}

void init(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n ;j++){
			int t;
			cin >> t;
			map[i][j]=t;
			if(t==9){
				sx=i;	sy=j;
			}
		}
	}	
	
	return ;
}

bool bfs(int x, int y){ // 이동하고 먹는것까지 
	int dist=0;
	queue<vector<int> > q;
	bool visit[n][n];
	memset(visit, 0, sizeof(visit));
	
	q.push({x, y});
	visit[x][y]=true;
	
	bool flag=false;
	while(!q.empty()){
		dist++;
		
		int q_size=q.size();
		for(int z=0; z<q_size; z++){
			int tx=q.front()[0], ty=q.front()[1];
			q.pop();
			
			for(int i=0; i<4; i++){
				int nx=tx+dx[i], ny=ty+dy[i];	
				if(nx<0 || n<=nx || ny<0 || n<=ny || visit[nx][ny] || shark<map[nx][ny]) continue;
				
				if(shark>map[nx][ny] && map[nx][ny]!=0){
					eatable.push_back({nx, ny});				
					flag=true;
				}
				
				q.push({nx, ny});
				visit[nx][ny]=true;			
			}
		}
		
		if(flag){
			ans+=dist;
			return true;
		}
	}
		
	return false;
}

bool eat(){  
	if(!bfs(sx, sy)) return false;
	sort(eatable.begin(), eatable.end(), compare);
	
	map[sx][sy]=0;
	sx=(*eatable.begin())[0];	sy=(*eatable.begin())[1];
	map[sx][sy]=9;
		
	cnt++;
	if(cnt==shark){
		cnt=0;
		shark++;
	}	
	
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();

	while(1){	
		if(!eat()) break;
		eatable.clear();
	}
	
	cout << ans;	
	return 0;
}
