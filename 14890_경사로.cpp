#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321
using namespace std;

int n, l, map[100][100], ans;
bool visit[100][100];

void init(){
	cin >> n >> l;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) cin >> map[i][j];
	}
	return ;
}

bool isRunway(int x, int y, int dir){
	if(dir==1){	
		if(map[x][y-1]<map[x][y]){
			int ty=y-1, cnt=0;
			while(1){
				cnt++;
				if(cnt==l){
					for(int k=ty; k<ty+l; k++){
						if(visit[x][k]) return false;
						visit[x][k]=true;
					}
					return true;
				}
				ty--;
				if(ty<0 || map[x][ty]!=map[x][ty+1]) return false;
			}
		}
		else if(map[x][y-1]>map[x][y]){
			int ty=y, cnt=0;
			while(1){
				cnt++;
				if(cnt==l){
					for(int k=ty; k>ty-l; k--){
						if(visit[x][k]) return false;
						visit[x][k]=true;
					}
					return true;
				}
				ty++;
				if(ty>=n || map[x][ty]!=map[x][ty-1]) return false; 
			}
		}
	}
	else{
		if(map[x-1][y]<map[x][y]){
			int tx=x-1, cnt=0;
			while(1){
				cnt++;
				if(cnt==l){
					for(int k=tx; k<tx+l; k++){
						if(visit[k][y]) return false;
						visit[k][y]=true;
					}
					return true;
				}
				tx--;
				if(tx<0 || map[tx][y]!=map[tx+1][y]) return false; 
			}
		}
		else if(map[x-1][y]>map[x][y]){
			int tx=x, cnt=0;
			while(1){
				cnt++;
				if(cnt==l){
					for(int k=tx; k>tx-l; k--){
						if(visit[k][y]) return false;				
						visit[k][y]=true;
					}
					return true;
				}
				tx++;
				if(tx>=n || map[tx][y]!=map[tx-1][y]) return false; 
			}
		}
	}
}

int checkPath(int r, int c){
	if(c==-1){
		int tmp=map[r][0];
		for(int j=1; j<n; j++){
			if(tmp!=map[r][j]){
				if(abs(tmp-map[r][j])>=2) return 0;
				if(isRunway(r, j, 1)) tmp=map[r][j];
				else return 0;
			}
		}
	}
	else{
		int tmp=map[0][c];
		for(int i=1; i<n; i++){
			if(tmp!=map[i][c]){
				if(abs(tmp-map[i][c])>=2) return 0;
				if(isRunway(i, c, 0)) tmp=map[i][c];
				else return 0;
			}			
		}		
	}
	
	return 1;
}

void checkPaths(){
	for(int i=0; i<n; i++){
		ans+=checkPath(i, -1);
	}

	memset(visit, 0, sizeof(visit));	

	for(int i=0; i<n; i++){
		ans+=checkPath(-1, i);
	}
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();
	checkPaths();
	
	cout << ans;
	return 0;
}
