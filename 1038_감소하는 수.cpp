#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;

void solve(){
	queue<long long> q;
	for(int i=0; i<10; i++){
		q.push(i);
	}
	
	int idx=0;
	long long t;
	while(!q.empty() && idx<=n){
		t=q.front();
		q.pop();
		
		int last=t%10;
		for(int i=0; i<last; i++){
			q.push(t*10+i);
		}	
		
		idx++;
	}
	
	if(idx-1==n) cout << t;
	else cout << -1;
	
}

int main(){
	cin >> n;
	solve();
		
	return 0;
}
