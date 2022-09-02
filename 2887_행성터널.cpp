#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h> // abs 사용 
#define MAX 100000
using namespace std;

int n;
vector<pair<int, int> > distX, distY, distZ;
//크루스칼 관련 변수
int parent[MAX];

int getParent(int x){
	if(parent[x]==x) return x;
	return parent[x]=getParent(parent[x]);
}

void unionParent(int a, int b){
	a=getParent(a);
	b=getParent(b);
	
	if(a<b) parent[b]=a;
	else parent[a]=b;
	
	return ;
}

bool findParent(int a, int b){
	a=getParent(a);
	b=getParent(b);
	
	if(a==b) return 1;
	return 0;
}

int main(){
	cin >> n;
//1. sort 적용 
	int x, y, z;
	for(int i=0; i<n; i++){
		cin >> x >> y >> z;
		distX.push_back({x, i});
		distY.push_back({y, i});
		distZ.push_back({z, i});
	}
	sort(distX.begin(), distX.end());
	sort(distY.begin(), distY.end());
	sort(distZ.begin(), distZ.end());
	
	vector<pair<int, pair<int, int> > > dist;
	for(int i=0; i<n-1; i++){
		dist.push_back({abs(distX[i].first-distX[i+1].first), {distX[i].second, distX[i+1].second}});
		dist.push_back({abs(distY[i].first-distY[i+1].first), {distY[i].second, distY[i+1].second}});
		dist.push_back({abs(distZ[i].first-distZ[i+1].first), {distZ[i].second, distZ[i+1].second}});
	}
	sort(dist.begin(), dist.end());
//2. 크루스칼 적용 
	for(int i=0; i<n; i++){
		parent[i]=i;
	}
	
	int ans=0, cnt=0, len=dist.size();
	for(int i=0; i<len; i++){
		if(cnt==n-1) break;
			
		if(!findParent(dist[i].second.first, dist[i].second.second)){
			ans+=dist[i].first;
			cnt++;
			unionParent(dist[i].second.first, dist[i].second.second);
		}
	}

	cout << ans;
	
	return 0;
}

