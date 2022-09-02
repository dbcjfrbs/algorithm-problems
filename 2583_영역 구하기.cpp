#include <iostream>
using namespace std;
int N, M, K;
int map[101][101]={0};
int area[10000];
int area_cnt=0;

bool isWall(int x, int y){
	if(x<1 || x>N || y<1 || y>M) return 1;
	return 0;
}

int bfs(int x, int y){ // dfs인듯  
	if(map[x][y]==1) return 0;
	map[x][y]=1;
	area_cnt++;

	int dx[4]={1, 0, -1, 0};
	int dy[4]={0, 1, 0, -1};
	for(int i=0; i<4; i++)
		if(!isWall(x+dx[i], y+dy[i])) bfs(x+dx[i], y+dy[i]);
	
	return 1;
}

int main(){
//입력 
	cin >> M >> N >> K;
	for(int i=0; i<K; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		for(int j=x1+1; j<=x2; j++)
			for(int k=y1+1; k<=y2; k++)
				map[j][k]=1;
	}
//카운트 
	int cnt=0;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			if(bfs(i, j)){
				area[cnt++]=area_cnt;
				area_cnt=0;
			}
//오름차순 정렬	
	for(int i=cnt-2; i>=0; i--)
		for(int j=0; j<=i; j++)
			if(area[j]>area[j+1]){
				int t=area[j];
				area[j]=area[j+1];
				area[j+1]=t;
			}
//출력 
	cout << cnt << endl;
	for(int i=0; i<cnt; i++){
		cout << area[i] << " ";
	}
	return 0;
}
