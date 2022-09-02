#include <iostream>
#define INF 10001
using namespace std;

int n, k;
int coins[100], d[10001];

int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> coins[i];
	}
	
	for(int i=0; i<=k; i++){
		d[i]=INF; // ÃÊ±âÈ­
		
		for(int j=0; j<n; j++){
			if(i-coins[j]>0 && d[i-coins[j]]+1<d[i]) d[i]=d[i-coins[j]]+1;
			else if(i-coins[j]==0) d[i]=1;
		}
	}
	
	if(d[k]==INF) cout << -1;
	else cout << d[k];
	
	return 0;
}
