#include <iostream>
#include <vector>
#include <queue>
#define MAX 100
using namespace std;
int n, m;
int map[MAX][MAX], visit[MAX][MAX];
int ans=MAX*6; // 프로그램 리턴값
// bfs를 위한 변수
int landCnt=1;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
// 그래프를 위한 변수
int dist[7][7];
// dfs를 위한 변수
int a[7];

void bfs(int x, int y, int cnt){
	queue<pair<int, int> > q;
	q.push({x, y});
	visit[x][y]=1;
	map[x][y]=cnt;
	
	pair<int, int> t;
	while(!q.empty()){
		t=q.front();
		q.pop();
		
		int nx, ny;
		for(int i=0; i<4; i++){
			nx=t.first+dx[i]; ny=t.second+dy[i];
			if(nx<0 || n<nx || ny<0 || m<ny) continue;
			if(visit[nx][ny]==1 || map[nx][ny]==0) continue;
			
			q.push({nx, ny});
			visit[nx][ny]=1;
			map[nx][ny]=cnt;
		}
	}

	return ;
}

void get_dist(int r, int c){
	int land1, land2;

	bool flag=0; int d=0;
	for(int i=0; i<c; i++){
		if(map[r][i]!=0 && !flag){
			land1=map[r][i];
			flag=1;
		}
		if(map[r][i]==0 && flag){
			d++;
		}
		if(map[r][i]!=0 && flag){
			land2=map[r][i];
			if(2<=d && d<dist[land1][land2]){
				dist[land1][land2]=d;
				dist[land2][land1]=d;
			}

			land1=map[r][i];
			d=0;			
		}
	}
	
	return ;
}

void dfs(int sum, int cnt, int start){
	a[start]=1;
	if(cnt==1){
		if(ans>sum) ans=sum;
		a[start]=0;

		return ;
	}
	
	for(int i=1; i<=landCnt; i++){
		for(int j=1; j<=landCnt; j++){
			if(a[i]==1 && dist[i][j]!=MAX && a[j]==0){
				dfs(sum+dist[i][j], cnt-1, j);
			}
			
		}
	}
	a[start]=0;
	
	return ;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> map[i][j];
		}
	}
//1.bfs로 섬마다 영역 구분하기
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(map[i][j]==1 && visit[i][j]==0) bfs(i, j, landCnt++);
		}
	}	
//2. 각 섬 간 최소거리 그래프 구하기 
//	memset(dist, 100, sizeof(dist)); // memset 초기화 알아두기
	for(int i=1; i<=landCnt-1; i++){
		for(int j=1; j<=landCnt-1; j++){
			dist[i][j]=MAX;
		}
	}	

	for(int i=0; i<n; i++){
		get_dist(i, m);
	}
	
	int tmp;
	for(int i=0; i<100; i++){
		for(int j=i+1; j<100; j++){
			tmp=map[i][j];
			map[i][j]=map[j][i];
			map[j][i]=tmp;		 
		}
	}
	
	for(int i=0; i<m; i++){
		get_dist(i, n);
	}
//3. 완전탐색을 통한 전체 섬 연결하는 최소 거리 구하기
	landCnt-=1; // 섬 영역 개수

	dfs(0, landCnt, 1);
	if(ans==MAX*6) cout << -1;
	else cout << ans;
		
	return 0;
}
