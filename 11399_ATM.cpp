#include <iostream>
using namespace std;
int n;
int order[1000], time_cnt[1001]={0};

int main(){
	cin >> n;
// 입력 
	for(int i=0; i<n; i++){
		int t;
		cin >> t;
		time_cnt[t]++;
	}
// 카운트정렬 
	int idx=0;
	for(int i=1; i<=1000; i++){
		while(time_cnt[i]--){
			order[idx++]=i;
		}
	}
// 계산 
	int ans=0;
	for(int i=0; i<n; i++){
		ans+=order[i]*(n-i);
	}
	cout << ans;
		
	return 0;
}
