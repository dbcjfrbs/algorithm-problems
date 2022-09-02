#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321
using namespace std;

int n, m, sx, sy, k, map[20][20], cmd[1000];
int dx[5]={0, 0, 0, -1, 1}, dy[5]={0, 1, -1, 0, 0};
int dice[4][3]={ // 주사위 전개도 
	{0, 0, 0},
	{0, 0, 0},
	{0, 0, 0},
	{0, 0, 0}
};


void init(){
	cin >> n >> m >> sx >> sy >> k;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> map[i][j];
	}
	for(int i=0; i<k; i++) cin >> cmd[i];
	return ;
}

void update_dice(int dir){
	int tmp;
	if(dir==1){
		tmp=dice[1][0];
		dice[1][0]=dice[1][1];
		dice[1][1]=dice[1][2];
		dice[1][2]=dice[3][1];
		dice[3][1]=tmp;
	}
	else if(dir==2){
		tmp=dice[1][2];
		dice[1][2]=dice[1][1];
		dice[1][1]=dice[1][0];
		dice[1][0]=dice[3][1];
		dice[3][1]=tmp;
	}
	else if(dir==3){
		tmp=dice[0][1];
		dice[0][1]=dice[3][1];
		dice[3][1]=dice[2][1];
		dice[2][1]=dice[1][1];
		dice[1][1]=tmp;
	}
	else{
		tmp=dice[0][1];
		dice[0][1]=dice[1][1];
		dice[1][1]=dice[2][1];
		dice[2][1]=dice[3][1];
		dice[3][1]=tmp;
	}
	
	return ;
}

void update_dice_map(int x, int y){
	if(map[x][y]==0){
		map[x][y]=dice[1][1];
	}
	else{
		dice[1][1]=map[x][y];
		map[x][y]=0;
	}
	
	return ;
}

void run(int x, int y, int dir){
	int nx=x+dx[dir], ny=y+dy[dir];
	if(nx<0 || n<=nx || ny<0 || m<=ny) return ;
	// 주사위 전개도 최신화 
	update_dice(dir);	
	//옮겨진 좌표 최신화
	sx=nx; sy=ny;
	// 주사위 및 지도 최신화
	update_dice_map(sx, sy);
	
	cout << dice[3][1] << '\n';
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();

	for(int i=0; i<k; i++){
		run(sx, sy, cmd[i]);
	}	
	
	return 0;
}
