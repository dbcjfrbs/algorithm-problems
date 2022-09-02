#include <iostream>
using namespace std;

int r, c, k, ans;
char map[6][6];
bool visit[6][6];
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

void dfs(int x, int y, int k){
	if(k==0 && x==0 && y==c-1){
		ans++;
		return ;
	}
	if(k<=0) return ;

	visit[x][y]=true;	
	for(int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		
		if(nx<0 || r<=nx || ny<0 || c<=ny || visit[nx][ny] || map[nx][ny]=='T') continue;
		dfs(nx, ny, k-1);
	}
	visit[x][y]=false;	
		
	return ;
}

int main(){
	cin >> r >> c >> k;
	for(int i=0; i<r; i++) cin >> map[i];
	
	dfs(r-1, 0, k-1);
	cout << ans;
}
