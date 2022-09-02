#include <iostream>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	
	int cnt=0, i;
	for(i=1; i<=n; i++){
		if(n%i==0) cnt++;
		if(cnt==k) break;
	}
	if(i==n+1) cout << 0; 
	else cout << i;
	
	return 0;
}
