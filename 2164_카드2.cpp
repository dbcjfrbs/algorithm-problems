#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321
using namespace std;

void solve(){
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	int n;
	cin >> n;
	queue<int> q;
	for(int i=1; i<=n; i++) q.push(i);
	for(int i=0; i<n-1; i++){
		q.pop();
		
		int tmp=q.front();
		q.pop();
		q.push(tmp);
	} 

	cout << q.front();	
	return 0;
}
