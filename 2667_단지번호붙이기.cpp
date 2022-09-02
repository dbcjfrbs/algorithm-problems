#include <stdio.h>
#include <iostream>
using namespace std;
int N;
char map[26][26];
char qx[30*30], qy[30*30];
int f=-1, r=-1;

bool isWall(int x, int y){
	if(x<0 || x>=N || y<0 || y>=N) return 1;
	return 0;
}

int bfs(int x, int y){
	qx[++r]=x; qy[r]=y;
	map[x][y]='0'; //중요함, 큐에 넣자마자 방문처리해줘야 함, 안그러면 중복가능성 있음
		
	int dx[4]={1, 0, -1, 0};
	int dy[4]={0, 1, 0, -1};	
	while(f!=r){
		int tx=qx[++f]; int ty=qy[f];

		for(int i=0; i<4; i++){
			int nx=tx+dx[i]; int ny=ty+dy[i];
			if(!isWall(nx, ny)){
				if(map[nx][ny]=='1'){
					qx[++r]=nx; qy[r]=ny;
					map[nx][ny]='0';
				}
			}
		}
	}		
	
	return r+1;
}

int main(){
	cin >> N;
	for(int i=0; i<N; i++)
		scanf("%s", map[i]);

	int cnt1=0;
	int cnt2_arr[26*13];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(map[i][j]=='1'){
				cnt2_arr[cnt1++]=bfs(i, j);
				f=r=-1;
			}
		}
	}
// 오름차순 정렬
	for(int i=cnt1-2; i>=0; i--)
		for(int j=0; j<=i; j++){
			if(cnt2_arr[j]>cnt2_arr[j+1]){
				int temp=cnt2_arr[j];
				cnt2_arr[j]=cnt2_arr[j+1];
				cnt2_arr[j+1]=temp;
			}
		} 
//출력
	cout << cnt1 << endl;
	for(int i=0; i<cnt1; i++){
		cout << cnt2_arr[i] << endl;
	}
	return 0;
} 
