#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 

int n, m, ans=64;
char map[50][51], chass1[50][51], chass2[50][51];
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

void init(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> map[i];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if((i%2==0 && j%2==0) || (i%2==1 && j%2==1)){
				chass1[i][j]='B';
				chass2[i][j]='W';
			}
			else{
				chass1[i][j]='W';
				chass2[i][j]='B';
			}
		}
	}
	return ;
}

int isChass(int x, int y){
//	for(int i=x; i<x+8; i++){
//		for(int j=y; j<y+8; j++){
//			if(map[i][j]=='B') b_cnt++;
//			
//			for(int k=0; k<4; k++){
//				int nx=i+dx[k], ny=j+dy[k];
//				if(nx<0 || n<=nx || ny<0 || m<=ny) continue;
//				if(map[nx][ny]==map[i][j]) return 100;
//			}
//		}
//	}
	
	int cnt1=0, cnt2=0;
	for(int i=x; i<x+8; i++){
		for(int j=y; j<y+8; j++){
			if(map[i][j]!=chass1[i][j]) cnt1++;
			if(map[i][j]!=chass2[i][j]) cnt2++;
		}
	}

	return min(cnt1, cnt2);
}

int main(){
	init();
	
	for(int i=0; i<n-7; i++){
		for(int j=0; j<m-7; j++){
			int cnt=isChass(i, j);
			if(cnt<ans) ans=cnt;
		}
	}	
	
	cout << ans;	
	return 0;
}
