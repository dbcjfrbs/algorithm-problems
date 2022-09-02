#include <iostream>
#include <vector>
#include <string.h>
#define MAX 100001
using namespace std;

int n;
vector<pair<int, int> > G[MAX]; // 정점, 거리
int visit[MAX];
// dfs에 사용되는 변수 
int firstDist, firstNode;

void dfs(int node, int dist){
	visit[node]=1;
	
	if(firstDist<dist){
		firstDist=dist;
		firstNode=node;
	}
	
	int len=G[node].size();
	for(int i=0; i<len; i++){
		if(visit[G[node][i].first]==0) dfs(G[node][i].first, dist+G[node][i].second);
	}	
	
	return ;
}

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin >> n;
	int idx, node, dist;
	for(int i=1; i<=n; i++){
		cin >> idx;
		while(1){
			cin >> node;
			if(node==-1) break;

			cin >> dist;			
			G[idx].push_back({node, dist});
			G[node].push_back({idx, dist});	
		}
	}

	dfs(1, 0);
	memset(visit, 0, sizeof(visit));
	
	dfs(firstNode, 0);
	cout << firstDist;
	
	return 0;
}
