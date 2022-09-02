#include <stdio.h>
#include <iostream>

using namespace std;
int n, m;
char map[11][11];
int visit[11][11][11][11]={0};
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

struct POINT{
	int rx, ry, bx, by;
};
POINT q[10000];

void modify(int dir, POINT *p, POINT *np){
	if(dir==1){
		if(p->ry > p->by) np->by-=1;
		else{
			np->ry-=1;
		} 
	}
	else if(dir==0){
		if(p->rx > p->bx) np->bx-=1;
		else np->rx-=1;
	}
	else if(dir==3){
		if(p->ry > p->by) np->ry+=1;
		else np->by+=1;
	}
	else{
		if(p->rx > p->bx) np->rx+=1;
		else np->bx+=1;
	}
	
	return ;
}

void bfs(int rx, int ry, int bx, int by){
	int r=-1, f=-1;
	q[++r]={rx, ry, bx, by};
	visit[rx][ry][bx][by]=1;
	
	POINT p;
	while(r!=f){
		p=q[++f];
		
		for(int i=0; i<4; i++){
			int finish=0;
			int nrx=p.rx, nry=p.ry, nbx=p.bx, nby=p.by;
			while(map[nrx+dx[i]][nry+dy[i]]!='#'){
				nrx=nrx+dx[i]; nry=nry+dy[i];
				if(map[nrx][nry]=='O') finish=1;
			}
			while(map[nbx+dx[i]][nby+dy[i]]!='#'){
				nbx=nbx+dx[i]; nby=nby+dy[i];
				if(map[nbx][nby]=='O') finish=-1;
			}
			if(finish==-1) continue;
			if(finish==1){
				if(visit[p.rx][p.ry][p.bx][p.by]>10) cout << -1;
				else cout << visit[p.rx][p.ry][p.bx][p.by];
				return ;
			}

			POINT np={nrx, nry, nbx, nby};
			if(nrx==nbx && nry==nby){
				modify(i, &p, &np);
			}
			
			if(visit[np.rx][np.ry][np.bx][np.by]) continue;

			q[++r]={np.rx, np.ry, np.bx, np.by};
			visit[np.rx][np.ry][np.bx][np.by]=visit[p.rx][p.ry][p.bx][p.by]+1;
		}
	}

	cout << -1;
	return ;
}

int main(){
//	cin >> n >> m;
	scanf("%d %d", &n, &m);
	
	int rx, ry, bx, by;
	for(int i=0; i<n; i++){
//		cin >> map[i];
		scanf("%s", map[i]);
		for(int j=0; j<m; j++){
			if(map[i][j]=='R'){
				rx=i; ry=j;
			}
			if(map[i][j]=='B'){
				bx=i; by=j;				
			}
		}
	}

	bfs(rx, ry, bx, by);
	
	return 0;
}
