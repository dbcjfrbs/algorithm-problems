#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321
using namespace std;

int n, m, f, map[21][21], sx, sy, ans;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
vector<vector<int> > dest;

void init(){
	cin >> n >> m >> f;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++) cin >> map[i][j];
	}	
	cin >> sx >> sy;
	for(int i=0; i<m; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		map[a][b]=i+2;
		dest.push_back({c, d, i+2});
	}
	ans=f;
	
	return ;
}

bool compare(vector<int> a, vector<int> b){
	if(a[0]==b[0]) return a[1]<b[1];
	return a[0]<b[0];
}

int bfs1(int x, int y){
	int ret;
	if(map[x][y]>=2){
		ret=map[x][y];
		map[x][y]=0;
		return ret;
	}
	
	queue<vector<int> > q;
	int visit[n+1][n+1];
	memset(visit, 0, sizeof(visit));
	
	q.push({x, y});
	visit[x][y]=1;
	
	bool finded=false;
	vector<vector<int> > candi;
	while(!q.empty()){
		int q_size=q.size();
		while(q_size--){
			int tx=q.front()[0], ty=q.front()[1];
			q.pop();
			
			for(int i=0; i<4; i++){
				int nx=tx+dx[i], ny=ty+dy[i];
				if(nx<=0 || n<nx || ny<=0 || n<ny || visit[nx][ny]!=0 || map[nx][ny]==1) continue;
				
				if(map[nx][ny]>=2){
					finded=true;
					candi.push_back({nx, ny});					
				}
				
				q.push({nx, ny});
				visit[nx][ny]=visit[tx][ty]+1;				
			} 
		}
		
		if(finded) break;
	}
	if(!finded){
		ans=-1;
		return 0;		
	}
	sort(candi.begin(), candi.end(), compare);	
	sx=candi[0][0];	sy=candi[0][1];
	
	int f_use=visit[sx][sy]-1;
	if(f_use>ans){
		ans=-1;
		return 0;
	}
	ans-=f_use;
	
	ret=map[sx][sy];
	map[sx][sy]=0;
	
	return ret;
}

void bfs2(int x, int y, int dex, int dey){
	queue<vector<int> > q;
	int visit[n+1][n+1];
	memset(visit, 0, sizeof(visit));
	
	q.push({x, y});
	visit[x][y]=1;
	
	bool finded=false;
	while(!q.empty()){
		int q_size=q.size();
		while(q_size--){
			int tx=q.front()[0], ty=q.front()[1];
			q.pop();
			
			for(int i=0; i<4; i++){
				int nx=tx+dx[i], ny=ty+dy[i];
				if(nx<=0 || n<nx || ny<=0 || n<ny || visit[nx][ny]!=0 || map[nx][ny]==1) continue;
				
				if(nx==dex && ny==dey){
					finded=true;
					sx=dex;	sy=dey;
				}
				
				q.push({nx, ny});
				visit[nx][ny]=visit[tx][ty]+1;				
				if(finded) break;
			} 
		}	
	}
	if(!finded){
		ans=-1;
		return ;		
	}
	
	int f_use=visit[sx][sy]-1;
	if(f_use>ans){
		ans=-1;
		return ;
	}
	ans+=f_use;
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();

	while(m--){
		int id=bfs1(sx, sy);
		if(ans==-1) break;
		
		int dex, dey, dest_size=dest.size();
		for(int i=0; i<dest_size; i++){
			if(dest[i][2]==id){
				dex=dest[i][0];	dey=dest[i][1];
				break;
			}
		}
		
		bfs2(sx, sy, dex, dey);
		if(ans==-1) break;
	}
	
	cout << ans;
	return 0;
}
