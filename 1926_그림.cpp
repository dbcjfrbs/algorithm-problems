#include <iostream>
using namespace std;

int n, m;
int map[500][500];
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
int cnt, area;

int dfs(int x, int y){
	map[x][y]=0;

	int ret=1;
	for(int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if(nx<0 || n<=nx || ny<0 || m<=ny) continue;		
		if(map[nx][ny]==1) ret+=dfs(nx, ny);
	}
	
	return ret;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> map[i][j];

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(map[i][j]==1){
				int t=dfs(i, j);
				if(area<t) area=t;
				cnt++;
			}	
		}		
	}
			
	cout << cnt << '\n' << area;	
	
	return 0;
}
