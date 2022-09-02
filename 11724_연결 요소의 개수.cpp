#include <iostream>
using namespace std;
int N, M;
int G[1001][1001]={0};
int q[1001];
int visited[1001]={0};

void bfs(int x){
	int f=-1, r=-1;
	q[++r]=x;
	visited[x]=1;
	
	while(f!=r){
		int t=q[++f];
		
		int nt_cnt=G[t][0];
		for(int i=1; i<=nt_cnt; i++){
			int nt=G[t][i];
			
			if(!visited[nt]){
				q[++r]=nt;
				visited[nt]=1;
			}
		}
		G[t][0]=0;
	}

	return ;				
}

int main(){
	cin >> N >> M;
	for(int i=0; i<M; i++){
		int u, v;
		cin >> u >> v;
		
		G[u][++G[u][0]]=v;
		G[v][++G[v][0]]=u;
	}
	
	
	
	int cnt=0;
	for(int i=1; i<=N; i++)
		if(G[i][0]==0) cnt++;
	
	for(int i=1; i<=N; i++){
		if(G[i][0]){
			bfs(i);
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}
