#include <iostream>
#include <vector>
using namespace std;

int n, k, arr[8], ans;

void comb(int depth, int sum, vector<bool> visit){
	if(depth==n){
		ans++;
		return ;
	}
	
	for(int i=0; i<n; i++){
		if(visit[i] || sum+arr[i]-k<500) continue;
		
		visit[i]=true;
		comb(depth+1, sum+arr[i]-k, visit);
		
		
		visit[i]=false;
	}
	
	return ;
}

int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++) cin >> arr[i];
	
	vector<bool> visit(n, 0);
	comb(0, 500, visit);
	
	cout << ans;
	
	return 0;
}
