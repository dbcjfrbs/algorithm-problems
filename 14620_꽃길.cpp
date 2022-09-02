#include <iostream>
using namespace std;

int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
int n, map[10][10], ans=3000; 

void init(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) cin >> map[i][j];
	}
	return ;
}

void comb(int depth, int x, int y, int sum, bool visit[10][10]){ // n이 안되는 거 정리하기 
	cout << depth << ' ';
	visit[x][y]=true;
	sum+=map[x][y];
	
	
	
	for(int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if(nx<0 || n<=nx || ny<0 || n<=ny || visit[nx][ny]){
			cout << 3;
			return ;
		}
		cout << i;
		sum+=map[nx][ny];
		visit[nx][ny]=true;
	}
	
	if(ans<=sum) return ;
	if(depth==2){
		ans=sum;
		return ;
	}
	for(int i=x; i<n; i++){
		for(int j=y; j<n; j++){
			if(visit[i][j]){
				continue;
			}
			comb(depth+1, i, j, sum, visit);		
		}
	}
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();

	bool visit[10][10]={0};
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			comb(0, i, j, 0, visit);
		}
	}
	
	cout << ans;
	
	return 0;
}
