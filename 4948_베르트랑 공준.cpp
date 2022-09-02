#include <iostream>
using namespace std;

int n;
bool checkNonPrime[300001];

void seive(){
	for(int i=2; i<=300000; i++){
		if(checkNonPrime[i]) continue;
		for(int j=i*2; j<=300000; j+=i){
			checkNonPrime[j]=true;
		}
	}
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	seive();
	while(1){
		cin >> n;
		if(!n) break;
		
		int cnt=0;
		for(int i=n+1; i<=2*n; i++){
			if(!checkNonPrime[i]) cnt++;
		}
		
		cout << cnt << '\n';
	}	
	
	return 0;
}
