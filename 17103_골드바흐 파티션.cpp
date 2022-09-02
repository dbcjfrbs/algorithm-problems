#include <iostream>
using namespace std;

int tc, n, ans;
bool prime[1000001];

void checkPrime(){
	for(int i=2; i<=500000; i++){
		for(int j=i; j<=1000000; j+=i){
			if(!prime[i] && j!=i) prime[j]=true;
		}
	}
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
		
	cin >> tc;
	checkPrime();

	while(tc--){
		cin >> n;
		
		ans=0;
		for(int i=2; i<=n/2; i++){
			if(!prime[i] && !prime[n-i]) ans++;
		}
		
		cout << ans << '\n';		
	}
	
	return 0;
}
