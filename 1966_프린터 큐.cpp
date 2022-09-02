#include <iostream>
#include <queue>
using namespace std;
// 23Ка 30УЪ 
int tc;

int run(queue<pair<int, int> > q, int priorities[10], int m){
	int priority=9, ret=0;
	while(!q.empty()){
		if(priorities[priority]==0){
			priority--;
			continue;
		}
		
		if(q.front().first==priority){
			ret++;
			if(q.front().second==m) return ret;

			q.pop();
			priorities[priority]--;
		}
		else{
			int a=q.front().first, b=q.front().second;
			q.pop();
			q.push({a, b});
		}
	}
}

int main(){
	cin >> tc;
	while(tc--){
		int n, m;
		queue<pair<int, int> > q;
		int priorities[10]={0, };

		cin >> n >> m;
		
		for(int i=0; i<n; i++){
			int priority;
			cin >> priority;
			q.push({priority, i});
			priorities[priority]++;
		}		
		
		cout << run(q, priorities, m) << '\n';
	}		
	
	return 0;
}
