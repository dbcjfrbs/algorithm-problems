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

int r, c, t, map[50][50], sx1, sx2, sy1, sy2;
int dx1[4]={-1, 0, 1, 0}, dy1[4]={0, 1, 0, -1};
int dx2[4]={1, 0, -1, 0}, dy2[4]={0, 1, 0, -1};


void init(){
	cin >> r >> c >> t;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin >> map[i][j];
			if(map[i][j]==-1){
				if(sx1==0){
					sx1=i;	sy1=j;
				}
				else{
					sx2=i;	sy2=j;	
				}				
			}
		}
	}
	return ;
}

void circulate(int x, int y){
	int dir=0;
	x+=dx1[dir];	y+=dy1[dir];
	while(1){		
		if(x+dx1[dir]<0 || r<=x+dx1[dir] || y+dy1[dir]<0 || c<=y+dy1[dir] || (y+dy1[dir]==c-1 && x+dx1[dir]==sx1+1)) dir++;
		int nx=x+dx1[dir], ny=y+dy1[dir];

		if(nx==sx1 && ny==sy1){
			map[x][y]=0;
			x=nx;	y=ny;
			break;
		}
				
		map[x][y]=map[nx][ny];
		x=nx;	y=ny;		

	}

	dir=0;
	x+=dx2[dir]+1;	y+=dy2[dir]; // 아래칸 이동 
	while(1){		
		if(x+dx2[dir]<0 || r<=x+dx2[dir] || y+dy2[dir]<0 || c<=y+dy2[dir] || (y+dy2[dir]==c-1 && x+dx2[dir]==sx2-1)) dir++;
		int nx=x+dx2[dir], ny=y+dy2[dir];

		if(nx==sx2 && ny==sy2){
			map[x][y]=0;
			break;
		}
		
		map[x][y]=map[nx][ny];
		x=nx;	y=ny;		
	}
	
	return ;
}

void diffuse(int x, int y, int (&map_)[50][50]){ // 인자 전달 중요 
	int cnt=0, tmp=map[x][y]/5;
	for(int i=0; i<4; i++){
		int nx=x+dx1[i], ny=y+dy1[i];
		if(nx<0 || r<=nx || ny<0 || c<=ny || map[nx][ny]==-1) continue;
		
		map_[nx][ny]+=tmp;
		cnt++;
	}
	map[x][y]-=tmp*cnt;
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();

	while(t--){
		int map_[50][50];
		memset(map_, 0, sizeof(map_));
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				if(map[i][j]==0 || map[i][j]==-1) continue;
				diffuse(i, j, map_);
			}
		}
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				if(map[i][j]==-1) continue;
				map[i][j]+=map_[i][j];
			}
		}

		circulate(sx1, sy1);
	}
	
	int ans=0;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(map[i][j]==-1) continue;
			ans+=map[i][j];
		}
	}
	
	cout << ans;	
	return 0;
}
