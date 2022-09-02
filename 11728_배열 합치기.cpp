#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;

	int a[n], b[m];
	for(int i=0; i<n; i++)
		cin >> a[i];
	for(int i=0; i<m; i++)
		cin >> b[i];

	int sum=n+m;
	int a_idx=0, b_idx=0, ans[sum];
	int i;
	for(i=0; i<sum; i++){
		if(a_idx>n-1 || b_idx>m-1) break;
		
		if(a[a_idx]<b[b_idx]) {
			ans[i]=a[a_idx++];	
		}
		else{
			ans[i]=b[b_idx++];	
		}
	}

	if(a_idx>n-1){
		for(int j=i; j<sum; j++){
			ans[j]=b[b_idx++];
		}
	}	
	else{
		for(int j=i; j<sum; j++){
			ans[j]=a[a_idx++];
		}
	}
	
	for(int j=0; j<sum; j++){
		cout << ans[j] << ' ';
	}	
	
	return 0;
}
