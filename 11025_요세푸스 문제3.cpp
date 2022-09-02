#include <iostream>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	
	int ans=1;
	for(int i=2; i<=n; i++){
		ans=(ans+k-1)%i+1;	
	}
	cout << ans;
	return 0;
}
