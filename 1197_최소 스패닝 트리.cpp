#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321
using namespace std;

int e, v, parent[10001], ans;
vector<vector<int> > lines;

bool compare(vector<int> a, vector<int> b){
	return a[2]<b[2];
}

void init(){
	cin >> v >> e;
	
	for(int i=1; i<=v; i++) parent[i]=i;
	
	int a, b, c;
	for(int i=0; i<e; i++){
		cin >> a >> b >> c;
		lines.push_back({a, b, c});
	}		
	return ;
}

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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();	
	sort(lines.begin(), lines.end(), compare);

	for(int i=0; i<e; i++){
		if(sameParent(lines[i][0], lines[i][1])) continue;
		
 		unionParent(lines[i][0], lines[i][1]);
		ans+=lines[i][2];
	}
	
	cout << ans;
	return 0;
}
