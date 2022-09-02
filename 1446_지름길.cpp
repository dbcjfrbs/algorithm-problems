#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, D, ans=10001;
vector<vector<int> > v;

void init(){
	cin >> n >> D;
	for(int i=0; i<n; i++){
		int s, e, d;
		cin >> s >> e >> d;
		v.push_back({s, e, d});		
	}
	sort(v.begin(), v.end());	
	return ;
}

void dfs(int loc, int sum, int start, int n){
	if(loc<=D){
		if(ans>sum+(D-loc)) ans=sum+(D-loc);
		if(start==n) return ;
	}	
	else return ;
	
	for(int i=start; i<n; i++){
		int s=v[i][0], e=v[i][1], d=v[i][2];
		
		if(s<loc) continue;
		
		dfs(e, sum+(s-loc)+d, i+1, n);
		dfs(s, sum+(s-loc), i+1, n);
	}
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();
	dfs(0, 0, 0, n);
	
	cout << ans;
	return 0;
}
