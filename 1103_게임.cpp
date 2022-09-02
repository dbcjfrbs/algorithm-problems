#include <stdio.h>
#include <iostream>
#define MAX 50
using namespace std;
int n, m;
char map[MAX][MAX];
int visit[1<<6][MAX][MAX]={0};
int sx, sy, key=0;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

struct POINT{
	int x, y, key;
};
POINT q[(1<<5)*MAX*MAX];
int f=-1, r=-1;

int get_key(int x, int y, int key){
	int t=map[x][y]-'a';
	if(!(key & (1<<t))) return key+(1<<t);
	return key;
}

bool check_door(int x, int y, int key){
	int t=map[x][y]-'A';
	if(key & (1<<t)) return 1;
	else return 0;
}

void bfs(){
	q[++r]={sx, sy, key};
	visit[key][sx][sy]=1;

	POINT t;
	while(r!=f){
		t=q[++f];
		for(int i=0; i<4; i++){
			int nx=t.x+dx[i], ny=t.y+dy[i], nk=t.key;
			if(nx<0 || n<=nx || ny<0 || m<=ny || map[nx][ny]=='#') continue;
			if(map[nx][ny] >= 'A' && map[nx][ny] <= 'F'){ //bloxk 처리 필수 
				if(!check_door(nx, ny, nk)) continue;					
			}
			else if(map[nx][ny] >= 'a' && map[nx][ny] <= 'f') nk=get_key(nx, ny, nk);
			if(visit[nk][nx][ny]) continue;

			q[++r]={nx, ny, nk};
			visit[nk][nx][ny]=visit[t.key][t.x][t.y]+1;
			
			if(map[nx][ny]=='1'){
				cout << visit[nk][nx][ny]-1;
				return ;
			}
		}
	}
	cout << -1;
	
	return ;
}

int main(){
	scanf("%d %d\n", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%c", &map[i][j]);
			if(map[i][j]=='0'){
				sx=i; sy=j;
			}
		}
		getchar();
	}
	bfs();	

	return 0;
}
