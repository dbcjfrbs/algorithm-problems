#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 101
using namespace std;

int n, m, visit[MAX];
vector<vector<int> > G(101);
// 결과 저장하기 위한 값들 
int ans=10000, idx;

void bfs(int x){
	queue<int> q;
	q.push(x);
	visit[x]=1;

	while(!q.empty()){
		int t=q.front();
		q.pop();
		
		int len=G[t].size();
		for(int i=0; i<len; i++){
			int nx=G[t][i];
			if(visit[nx]==0){
				q.push(nx);
				visit[nx]=visit[t]+1;
			}
		}
	}	

	return ;	
}

int main(){
	cin >> n >> m;
	int a, b;
	for(int i=0; i<m; i++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	} 	

	for(int i=1; i<=n; i++){
		memset(visit, 0, sizeof(visit));
		bfs(i);
		
		int sum=0;
		for(int i=1; i<=n; i++){
			sum+=visit[i]-1;
		}
		
		if(sum<ans){
			ans=sum;
			idx=i;
		}
		
	}	
	
	cout << idx;
		
	return 0;
}
