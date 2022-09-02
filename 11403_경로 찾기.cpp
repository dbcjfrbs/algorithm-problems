#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int n, map[100][100], visit[100], ans[100][100];

void bfs(int x, int y){ // x가 방문할 수 있는 y에 1 체크하기 
	queue<int> q;
	
	q.push(y);
	visit[y]=1;
	ans[x][y]=1;
	
	while(!q.empty()){
		int t=q.front();
		q.pop();

		for(int i=0; i<n; i++){
			if(map[t][i] && !visit[i]){
				q.push(i);
				visit[i]=1;
				ans[x][i]=1;
			}
		}
	}
	
	return ;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> map[i][j];
		
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!visit[j] && map[i][j]){
				bfs(i, j);
			}
		}

		memset(visit, 0, sizeof(visit));
			
		for(int j=0; j<n; j++)
			cout << ans[i][j] << ' ';
		cout << endl;
	}	
	
	return 0;
}
