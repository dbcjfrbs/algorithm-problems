#include <iostream>
using namespace std;
int N, L;
int pipe[1001]={0};

int main(){
	cin >> N >> L;
	for(int i=1; i<=N; i++){ 
		int t;
		cin >> t;
		pipe[t]=1;
	}
	
	int ans=0, idx=1;
	while(idx<=1000){
		if(pipe[idx]){
			idx+=L;
			ans++;
		}
		else idx++;
	}
	cout << ans;
	
	return 0;
} 
