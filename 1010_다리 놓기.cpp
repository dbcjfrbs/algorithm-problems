//#include <iostream>
//using namespace std;
//
//int tc, n, m;
//long long ans;
//		
//int main(){
//	cin >> tc;
//	while(tc--){
//		cin >> n >> m;
//
//		ans=1;
//		for(int r=1; r<=n; r++){
//			ans*=m-r+1; 
//			ans/=r;		
//		}
//		
//		cout << ans << '\n';
//	}
//	
//	return 0;
//}

//2.dp 활용 풀이
#include<iostream>
using namespace std;
long long dp[31][31], ans;

int solve(int N,int K) {	
	if(K==1) return dp[N][1]=N;
	if(N<K) return 0;
	if(dp[N][K]!=0) return dp[N][K];

	return dp[N][K]=solve(N-1, K)+solve(N-1, K-1);
}

int main()
{		
	//입력받기
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, K;
		cin >> N >> K;
		//문제해결
		ans=solve(K, N);
		cout << ans << endl;
	}
	
	return 0;
}
