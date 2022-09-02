#include <iostream>
using namespace std;

int n, arr[10000], budget;
int s=1, e, mid;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		if(e<arr[i]) e=arr[i];
	}
	cin >> budget;
	
	while(1){
		mid=(s+e)/2;
		int sum=0;
//		cout << s<< ' ' << e << ' ' << mid << '\n';
		for(int i=0; i<n; i++){
			if(mid<arr[i]) sum+=mid;
			else sum+=arr[i];
			
			if(sum>budget){
				e=mid-1;
				break;
			}
			if(sum<=budget && i==n-1) s=mid;
		}

		if(s==e-1 || s==e) break;
	}
	
	for(int i=0; i<n; i++){
		if(e<arr[i]) budget-=e;
		else budget-=arr[i];
	}
		
	if(budget<0) cout << s;
	else cout << e;
	
	return 0;
}
