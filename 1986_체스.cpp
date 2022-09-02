#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, ans;
int map[1001][1001];
queue<pair<int, int> > q, k, p;
int dx[8]={1, 1, -1, -1, 1, 0, -1, 0}, dy[8]={1, -1, 1, -1, 0, 1, 0, -1};
int dx_k[8]={2, 1, -1, -2, -2, -1, 1, 2}, dy_k[8]={1, 2, 2, 1, -1, -2, -2, -1};

void init(){
	cin >> n >> m;
	
	int tmp, r, c;
	cin >> tmp;
	for(int i=0; i<tmp; i++){
		cin >> r >> c;
		q.push({r, c});
		map[r][c]=1;
	}
	cin >> tmp;
	for(int i=0; i<tmp; i++){
		cin >> r >> c;
		k.push({r, c});		
		map[r][c]=1;
	}
	cin >> tmp;
	for(int i=0; i<tmp; i++){
		cin >> r >> c;
		p.push({r, c});		
		map[r][c]=1;
	}

	return ;
}

void q_check(){
	int x, y;
	
	while(!q.empty()){
		x=q.front().first;	y=q.front().second;
		q.pop();
		
		for(int i=0; i<8; i++){
			int nx=x+dx[i], ny=y+dy[i];
			while(!(nx<1 || n<nx || ny<1 || ny>m) && map[nx][ny]!=1){
				map[nx][ny]=2;
				nx+=dx[i];	ny+=dy[i];
			}
		}
	}
	
	return ;
}

void k_check(){
	int x, y;
	while(!k.empty()){
		x=k.front().first;	y=k.front().second;
		k.pop();
			
		for(int i=0; i<8; i++){
			int nx=x+dx_k[i], ny=y+dy_k[i];
			if(nx<1 || n<nx || ny<1 || ny>m) continue;
			map[nx][ny]=2;
		}
	}

	return ;
}

int main(){
	init();	
	q_check();
	k_check();

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(map[i][j]==0) ans++;

	cout << ans;	
	return 0;
}
