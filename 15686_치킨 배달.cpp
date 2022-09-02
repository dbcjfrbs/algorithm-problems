#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h>
#include <queue>
#define INF 987654321
using namespace std;

int n, m, map[51][51], ans=INF, homes_size, stores_size;
vector<vector<int> > homes, stores;
bool visit[51][51], selected[51][51];
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

void init(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> map[i][j];
			if(map[i][j]==1) homes.push_back({i, j});
			else if(map[i][j]==2) stores.push_back({i, j});
		}
	}

	homes_size=homes.size();
	stores_size=stores.size();
	return ;
}

int minValue(int x, int y){
	int ret=INF;
	for(int i=0; i<stores_size; i++){
		int tx=stores[i][0], ty=stores[i][1];
		if(!selected[tx][ty]) continue;
		
		int dist=abs(tx-x)+abs(ty-y);
		if(ret>dist) ret=dist; 
	}
	
	return ret;
}

void comb(int depth, int start){
	if(depth==m){
		int sum=0;
		for(int i=0; i<homes_size; i++){
//			int ret=bfs(homes[i][0], homes[i][1], sum);
//			if(ret==-1) return ;
			sum+=minValue(homes[i][0], homes[i][1]);
			memset(visit, 0, sizeof(visit));
		}
		if(sum<ans) ans=sum;
			
		return ;
	}
	
	for(int i=start; i<stores_size-m+depth+1; i++) {
		int x=stores[i][0], y=stores[i][1];

		selected[x][y]=true;
		comb(depth+1, i+1);
		selected[x][y]=false;
	}
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	vector<vector<int> > a;
	comb(0, 0);
	
	cout << ans;
	return 0;
}

// 아래는 bfs 시간초과 났던 코드 일부분입니다. 

//int bfs(int x, int y, int &sum){
//	queue<vector<int> > q;
//	q.push({x, y});
//	visit[x][y]=true;
//	
//	while(!q.empty()){
//		int q_size=q.size();
//		bool flag=false;
//		while(q_size--){
//			int tx=q.front()[0], ty=q.front()[1];
//			q.pop();
//			
//			for(int i=0; i<4; i++){
//				int nx=tx+dx[i], ny=ty+dy[i];
//				if(nx<1 || n<nx || ny<1 || n<ny || visit[nx][ny]) continue;
//				if(map[nx][ny]==2 && selected[nx][ny]){
//					flag=true;
//					break;
//				}
//				
//				q.push({nx, ny});
//				visit[nx][ny]=true;
//			}		
//		}
//		sum++;
//		if(ans<sum) return -1;
//		if(flag) break;		
//	}
//	
//	return 1;	
//}


