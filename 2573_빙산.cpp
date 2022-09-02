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

int n, m, map[300][300], ans; 
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

void init(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> map[i][j];
		}
	}

 	return ;
}

bool isOne(int ice_cnt, pair<int, int> p){
	queue<pair<int, int> > q;
	bool visit[n][m];
	
	memset(visit, 0, sizeof(visit));
	q.push(p);
	visit[p.first][p.second]=true;
	ice_cnt--;
	
	while(!q.empty()){
		int tx=q.front().first, ty=q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx=tx+dx[i], ny=ty+dy[i];
			if(visit[nx][ny] || map[nx][ny]==0) continue;
						
			q.push({nx, ny});
			visit[nx][ny]=true;
			ice_cnt--;
		}
	}
	
	return ice_cnt==0;
}

bool year(){
	vector<pair<int, int> > ice;
	int melt[n][m], ice_cnt=0;
	memset(melt, 0, sizeof(melt));	

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(map[i][j]==0) continue;
			
			ice.push_back({i, j});
			ice_cnt++;

			int cnt=0;
			for(int k=0; k<4; k++){
				int nx=i+dx[k], ny=j+dy[k];
				if(map[nx][ny]==0) cnt++;
			}
			melt[i][j]=cnt;			
		}
	}
	
	pair<int, int> p;
	int ice_cnt_=ice_cnt;
	for(int i=0; i<ice_cnt; i++){
		int x=ice[i].first, y=ice[i].second;
		
		if(map[x][y]>melt[x][y]){
			map[x][y]-=melt[x][y];
			p={x, y};
		}
		else{
			map[x][y]=0;
			ice_cnt_--;			
		}
	}	
	
	if(ice_cnt_==0) return false;
	return isOne(ice_cnt_, p);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();

	do{		
		ans++;
	}while(year());
	
	bool flag=false;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(map[i][j]!=0) flag=true;
		}
	}
	
	if(flag) cout << ans;
	else cout << 0;
	
	return 0;
}
