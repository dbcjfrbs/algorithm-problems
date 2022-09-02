#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int n, m, cnt, maxx;
int visit[10001], ans[10001];
vector<int > a[10001];

void dfs(int x){
	visit[x]=1;
	cnt++;
	if(maxx<cnt) maxx=cnt;
	
	int size=a[x].size();
	for(int i=0; i<size; i++){
		if(visit[a[x][i]]) continue;
		dfs(a[x][i]);				
	}
	
	return ;
}

int main(){
	scanf("%d %d", &n, &m);	
	
	int x, y;
	for(int i=0; i<m; i++){
		scanf("%d %d", &x, &y);
		a[y].push_back(x);
	}
	
	for(int i=1; i<=n; i++){
		dfs(i);
		ans[i]=cnt;

		cnt=0;
		memset(visit, 0, sizeof(visit));
	}

	for(int i=1; i<=n; i++){
		if(ans[i]==maxx) cout << i << ' ';
	}

	return 0;
} 
