#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
using namespace std;

int n, m, map[50][50], r, c, d, ans;
bool visit[50][50];
int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};

void init(){
	cin >> n >> m >> r >> c >> d;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> map[i][j];
	}		
	return ;
}

int dfs(int x, int y, int dir){
	int ret=dir;
	if(!visit[x][y]) ans++;
	visit[x][y]=true;
	
	for(int i=dir-1; i>dir-5; i--){
		int t=(i+4)%4, nx=x+dx[t], ny=y+dy[t]; // �������� ���⵹���� ��ĭ ������ ĭ ��ǥ ���� 
		if(visit[nx][ny] || map[nx][ny]==1) continue; // �� ĭ�� û���߰ų�, ���̶�� for���� �ݺ��� ȸ���Ѵ� 
		 
		ret=dfs(nx, ny, t); // �� ĭ�� û������ ���� �� �����̶�� ����.
		if(ret==-1) return -1;
	}
	
	int bx=x+dx[(ret+2)%4], by=y+dy[(ret+2)%4]; // �� ĭ ��ǥ ���� 
	if(map[bx][by]!=1) return dfs(bx, by, ret); // �� ĭ�� ���� �ƴ϶��
	else return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();	
	dfs(r, c, d);
	
	cout << ans;
	return 0;
}
