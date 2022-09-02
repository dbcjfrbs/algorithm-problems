#include <iostream>
using namespace std;

int n, k;

int main(){
	cin >> n >> k;
	int kind[n];
	for(int i=1; i<=n; i++){
		cin >> kind[i];
	}		
	
	
	int ans=0;
	while(k){
		if(kind[n]<=k){
			k-=kind[n];
			ans++;
		}
		else n--;
		
	}
	
	cout << ans;
	
	return 0;
} 
