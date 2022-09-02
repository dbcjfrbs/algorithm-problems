#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, parent[100001], ans;
vector<vector<int> > v; 

int getParent(int x){
	if(parent[x]==x) return x;
	return parent[x]=getParent(parent[x]);
}

bool sameParent(int a, int b){
	a=getParent(a);
	b=getParent(b);
	return a==b;
}

void unionParent(int a, int b){
	a=getParent(a);
	b=getParent(b);
	if(a<b) parent[b]=a;
	else parent[a]=b;
	return ;
}

bool compare(vector<int> a, vector<int> b){
	return a[2]<b[2];
}

void init(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({a, b, c});
	}
	sort(v.begin(), v.end(), compare);
	
	for(int i=1; i<=n; i++) parent[i]=i;
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	int path_max=0, cnt=0;
	for(int i=0; i<m; i++){
		if(cnt==n-1) break;
		if(sameParent(v[i][0], v[i][1])) continue;

		unionParent(v[i][0], v[i][1]);
		ans+=v[i][2];	
		cnt++;
		
		path_max=v[i][2];
	}	
	ans-=path_max;
	cout << ans;
	
	return 0;
}
