#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, arr[501][501], d[501][501], ans;

void init(){
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++) cin >> arr[i][j];
	}	
	
	return ;
}

void solve(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			if(d[i][j]<d[i-1][j-1]+arr[i][j]) d[i][j]=d[i-1][j-1]+arr[i][j];
			if(d[i][j]<d[i-1][j]+arr[i][j]) d[i][j]=d[i-1][j]+arr[i][j];					
		}
	}	

	for(int i=1; i<=n; i++){
		if(ans<d[n][i]) ans=d[n][i];
	}
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();
	solve();
	
	cout << ans;
	return 0;
}
