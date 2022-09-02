#include <iostream>
using namespace std;

int d[31][31];

//int main(){
//	int n, k;
//	cin >> n >> k;
//	
//	for(int i=1; i<=n; i++){
//		d[i][1]=1;
//		d[i][i]=1;
//	}
//
//	for(int i=2; i<=n; i++){
//		for(int j=2; j<=k; j++){
//			d[i][j]=d[i-1][j-1]+d[i-1][j];
//		}
//	}	
//	
//	cout << d[n][k];
//	return 0;
//}

int dp(int nn, int kk){
	if(nn<kk) return 0;
	if(d[nn][kk]!=0) return d[nn][kk];
	return d[nn][kk]=dp(nn-1, kk)+dp(nn-1, kk-1);
} 

int main(){
	int n, k;
	cin >> n >> k;
	
	for(int i=1; i<=n; i++){
		d[i][1]=1;
		d[i][i]=1;
	}
		
	cout << dp(n, k);
	return 0;
}
