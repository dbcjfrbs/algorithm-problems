#include <iostream>
#include <vector>
using namespace std;

int n, m, node, benefit;
vector<vector<pair<int, int> > > G(100001);
int val[100001], visit[100001];

//void dfs(int idx, int sum){
//	visit[idx]=1;
//	
//	if(val[idx]!=0) sum+=val[idx];
//	if((benefit==sum && node>idx) || benefit<sum){
//		node=idx;
//		benefit=sum;
//	}
//	if(val[idx]!=0) sum-=val[idx];
//
//	int len=G[idx].size();
//	for(int i=0; i<len; i++){
//		int nidx=G[idx][i].first, pay=G[idx][i].second;
//		if(visit[nidx]==1) continue;
//		
//		dfs(nidx, sum-pay*2);
//	}	
//	
//	return ;
//}
void dfs(int idx, int sum){
	visit[idx]=1;
	
	if((benefit==sum && node>idx) || benefit<sum){
		node=idx;
		benefit=sum;
	}
	if(val[idx]!=0) sum-=val[idx];

	int len=G[idx].size();
	for(int i=0; i<len; i++){
		int nidx=G[idx][i].first, pay=G[idx][i].second;
		if(visit[nidx]==1) continue;
		
		dfs(nidx, sum-pay*2+val[nidx]);
	}	
	
	return ;
}

int main(){
	cin >> n >> m;
	int a, b, c;
	for(int i=0; i<n-1; i++){
		cin >> a >> b >> c;
		G[a].push_back({b, c});
		G[b].push_back({a, c});
	}
	int x, v;
	for(int i=0; i<m; i++){
		cin >> x >> v;
		val[x]=v;
	}

	node=n;
	dfs(1, 0);
	
	cout << node << ' ' << benefit;
	return 0;
}
