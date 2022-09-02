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

int n, k; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	cin >> n >> k;
	queue<int> q;
	for(int i=1; i<=n; i++) q.push(i);
	
	cout << '<';
	int cnt=0;
	while(!q.empty()){
		cnt++;
		
		if(cnt%k==0){
			cout << q.front();
			if(q.size()!=1) cout << ", ";
			q.pop();
			cnt=0;
			continue;
		}		
		int tmp=q.front();
		q.pop();
		q.push(tmp);		
	}
	cout << '>';
	
	return 0;
}
