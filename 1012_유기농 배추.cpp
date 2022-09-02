#include <iostream>
using namespace std;
int m, n, k;
int map[50][50];
struct POS{
	int x, y;
};
POS q[50*50];

void bfs(int x, int y){
	int f=-1, r=-1;
	q[++r]={x, y};
	map[x][y]=0;
	
	while(f!=r){
		int tx=q[++f].x, ty=q[f].y;
		if(tx>0 && map[tx-1][ty]==1){
			q[++r]={tx-1, ty}; map[tx-1][ty]=0;
		}
		if(tx<m-1 && map[tx+1][ty]==1){
			q[++r]={tx+1, ty}; map[tx+1][ty]=0;
		}
		if(ty>0 && map[tx][ty-1]==1){
			q[++r]={tx, ty-1}; map[tx][ty-1]=0;
		}
		if(ty<n-1 && map[tx][ty+1]==1){
			q[++r]={tx, ty+1}; map[tx][ty+1]=0;
		}	
	}
	
	return ;
} 

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> m >> n >> k;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				map[i][j]=0;
			}
		}
		
		for(int i=0; i<k; i++){
			int x, y;
			cin >> x >> y;
			map[x][y]=1;
		}
		
		int ans=0;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(map[i][j]){
					bfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
