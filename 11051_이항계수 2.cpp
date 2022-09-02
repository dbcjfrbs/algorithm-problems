#include <iostream>
#include <vector>
using namespace std;

int n, k, ans=1;
int m[1000];

void solve(){
	for(int j=k; j>=2; j--){
		for(int i=0; i<k; i++){
			if(m[i]%j==0){
				m[i]/=j;
				break;
			}			
		}		
	}
	
	return ;
}

int main(){
	cin >> n >> k;
	for(int i=0; i<k; i++) m[i]=n-i;
	
	solve();
	for(int i=0; i<k; i++){
		ans=ans*m[i]%10007;
	}
		
	cout << ans;
	
	return 0;
}
