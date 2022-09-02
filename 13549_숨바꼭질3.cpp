#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int n, k, t[100001];

void dijkstra(){
	priority_queue<pair<int, int> > pq;
	pq.push({0, n});
	
	while(!pq.empty()){
		int time=pq.top().first*(-1), cur=pq.top().second;
		pq.pop();
		if(cur==k){
			cout << time;
			return ;
		}
		
		if(t[cur]<time) continue;
		
		int tmp=cur*2;
		while(tmp<100001){
			if(tmp==0) break;
			if(t[tmp]>time){
				t[tmp]=time;
				pq.push({-time, tmp});
			}
			tmp*=2;
		}
		
		if(cur+1<=100000 && t[cur+1]>time+1){
			t[cur+1]=time+1;
			pq.push({-(time+1), cur+1});
		} 
		if(cur-1>=0 && t[cur-1]>time+1){
			t[cur-1]=time+1;
			pq.push({-(time+1), cur-1});
		}		
	}	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	cin >> n >> k;
	
	for(int i=0; i<100001; i++) t[i]=INF;
	t[n]=0;
	dijkstra();
	
	return 0;
}
