#include <iostream>
using namespace std;

int n, k, arr[100000], sum, ans;

int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		if(i<k) sum+=arr[i];
	}
	
	ans=sum;
	for(int i=0; i<n-k; i++){
		sum=sum-arr[i]+arr[k+i];		
		if(ans<sum) ans=sum;	
	}
	
	cout << ans;
	return 0;
}
