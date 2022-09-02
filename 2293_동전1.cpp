#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int coin[100], d[10001];

int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++) cin >> coin[i];
	sort(coin, coin+n);
	
	d[0]=1;
	for(int i=0; i<n; i++){
		for(int j=coin[i]; j<=k; j++){
			if(j-coin[i]<0) continue;
			d[j]+=d[j-coin[i]];
		}
	}
// 밑의 코드는 중복이 포함되므로 주의. 
//	for(int i=1; i<=k; i++){
//		for(int j=0; j<n; j++){
//			if(i-coin[j]<0) continue;
//			d[i]+=d[i-coin[j]];
//		}
//	}

	cout << d[k];
	
	return 0;
}
