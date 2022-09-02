#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
vector<int> G[100001];
int parent[100001], visit[100001];

void dfs(int x){
	visit[x]=1;
	
	int nx, size=G[x].size();
	for(int i=0; i<size; i++){
		nx=G[x][i];
		if(visit[nx]==1) continue;

		parent[nx]=x;
		dfs(nx);
	}
	
	return ;
}

int main(){
	scanf("%d", &n);
	int a, b;
	for(int i=1; i<n; i++){
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);		
	}

	dfs(1);	
	for(int i=2; i<=n; i++){
		printf("%d\n", parent[i]);
	}
	
	return 0;
}
