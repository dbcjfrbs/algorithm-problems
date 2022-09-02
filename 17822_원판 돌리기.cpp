#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321
using namespace std;

int n, m, t, map[51][51], x, d, k, ans;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

void init(){
	cin >> n >> m >> t;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++) cin >> map[i][j];
	}
	return ;
}

void run(){
	if(d==0) k=m-k;
	for(int i=x; i<=n; i+=x){
		int tmp, xx[m+1];
		if(d==1){
			for(int j=k+1; j<=m+k; j++) xx[j-k]=map[i][(j-1)%m+1];	
			for(int j=1; j<=m; j++) map[i][j]=xx[j];
		}
		else{
			for(int j=k+1; j<=m+k; j++) xx[j-k]=map[i][(j-1)%m+1];				
			for(int j=1; j<=m; j++) map[i][j]=xx[j];
		}
	}	
	
	return ;
}

bool bfs(int x, int y){	
	queue<vector<int> > q;
	q.push({x, y});

	bool check[51][51];
	memset(check, 0, sizeof(check));
	check[x][y]=true;
	
	vector<vector<int> > removes;
	removes.push_back({x, y});
	while(!q.empty()){
		int tx=q.front()[0], ty=q.front()[1];
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx=tx+dx[i], ny=ty+dy[i];
			if(nx<=0 || n<nx || ny<=0 || m<ny || check[nx][ny]) continue;
			
			if(map[nx][ny]==map[tx][ty] && map[nx][ny]!=0){
				removes.push_back({nx, ny});
				q.push({nx, ny});
				check[nx][ny]=true;
			}
			
			// 예외처리 
			if((ty==1 || ty==m) && (map[tx][1]==map[tx][m]) && map[tx][1]!=0){
				if(ty==1){
					if(check[tx][m]) continue;
					removes.push_back({tx, m});
					q.push({tx, m});
					check[tx][m]=true;
				}
				else{
					if(check[tx][1]) continue;
					removes.push_back({tx, 1});
					q.push({tx, 1});
					check[tx][1]=true;					
				}			
			}						
		}
	}
	
	int removes_size=removes.size();
	if(removes_size!=1){
		for(int i=0; i<removes_size; i++) map[removes[i][0]][removes[i][1]]=0;
		return true;
	}
	
	return false;
}

void update(){
	int sum=0, cnt=0;
	bool remove=false;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(bfs(i, j)){
				remove=true;
				continue;
			}

			sum+=map[i][j];
			if(map[i][j]!=0) cnt++;
		}
	}

	if(!remove){
		double avg=(float)sum/(float)cnt;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(map[i][j]>avg) map[i][j]-=1;
				else if(map[i][j]<avg && map[i][j]!=0) map[i][j]+=1;
			}
		}
	}

	return ;
}

void solve(){
	run();
	update();
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();
	
	while(t--){
		cin >> x >> d >> k;
		solve();		
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			ans+=map[i][j];
		}
	}
	
	cout << ans;
	return 0;
}
