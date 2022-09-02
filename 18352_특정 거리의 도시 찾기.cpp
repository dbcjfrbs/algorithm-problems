#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321
typedef long long ll;
using namespace std;

int n, m, k, x, d[300001];
vector<int> arr[300001];

void init(){
	cin >> n >> m >> k >> x;
	int a, b;
	for(int i=0; i<m; i++){
		cin >> a >> b;
		arr[a].push_back(b);
	}
	for(int i=1; i<=n; i++) d[i]=INF;	
	return ;
}

void dijkstra(){
	priority_queue<pair<int, int> > pq;
	pq.push({0, x});
	d[x]=0;
	
	while(!pq.empty()){
		int cur=pq.top().second, dist=-pq.top().first;
		pq.pop();

		if(d[cur]<dist) continue;
		if(d[cur]>k) break;
		
		int next_size=arr[cur].size();
		for(int i=0; i<next_size; i++){
			int next=arr[cur][i], nextdist=dist+1;
			if(nextdist<d[next]){
				d[next]=nextdist;
				pq.push({-nextdist, next});
			}
		}		
	}		
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();
	dijkstra();
	
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(d[i]==k){
			cout << i << '\n';
			cnt++;
		}
	}
	if(cnt==0) cout << -1;
	
	return 0;
}
