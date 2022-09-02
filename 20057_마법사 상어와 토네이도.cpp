#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321
using namespace std;

int n, map[500][500], sx, sy, sand;
bool visit[500][500];
int dx[4]={0, 1, 0, -1}, dy[4]={-1, 0, 1, 0};
int ds1[10]={0, 0, -1, -1, 0, 0, 1, 1, 2, 1}, ds2[10]={2, -2, 1, -1, 1, -1, 1, -1, 0, 0};
float dr[10]={0.02, 0.02, 0.01, 0.01, 0.07, 0.07, 0.1, 0.1, 0.05, 0};

void init(){
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> map[i][j];
			sand+=map[i][j];
		}
	}	
	sx=n/2+1;	sy=n/2+1;
	return ;
}

void effect(int x, int y, int dir){
	int sum=0, nx, ny;
	for(int i=0; i<10; i++){
		if(dir%2==0){
			nx=x+ds2[i]; ny=y+dy[dir]*ds1[i];		
		}
		else{
			nx=x+dx[dir]*ds1[i]; ny=y+ds2[i];
		}
		int tmp=floor((float)map[x][y]*dr[i]);
		
		sum+=tmp;
		if(nx<=0 || n<nx || ny<=0 || n<ny) continue;
		
		map[nx][ny]+=tmp;

		if(i==9) map[nx][ny]+=(map[x][y]-sum);
	}
	map[x][y]=0;
	
	return ;
}

void run(int dir){	
//	if(sx==1 && sy==1) return ;
	int pdir=(dir+3)%4;
	while(1){
		if(sx==1 && sy==1) return ;
		if(visit[sx+dx[dir]][sy+dy[dir]]){
			sx+=dx[pdir];	sy+=dy[pdir];
						
			effect(sx, sy, pdir);
			visit[sx][sy]=true;
			continue;
		}
		
		sx+=dx[dir];	sy+=dy[dir];
		
		effect(sx, sy, dir);	
		visit[sx][sy]=true;

		break;
	}

	run((dir+1)%4);
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();

	visit[sx][sy]=true;
	run(0);	
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++) sand-=map[i][j];
	}	
	
	cout << sand;	
	return 0;
}
