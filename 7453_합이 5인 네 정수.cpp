#include <iostream>
#include <algorithm>
#define MAX 16000001
using namespace std;

int n, a[], b[], c[], d[];
int arr1[MAX], arr2[MAX];
int ans;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	
	int tmp=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			arr1[tmp]=a[i]+b[j];
			arr2[tmp++]=c[i]+d[j];
		}
	}
		
	sort(arr1, arr1+n);
	sort(arr2, arr2+n);
// 투포인터 계산	
	int idx1=n-1, idx2=0;
	while(idx1!=-1 && idx2!=n){
		if(arr1[idx1]+arr2[idx2]>0) idx1--;
		else if(arr1[idx1]+arr2[idx2]<0) idx2++;
		else{
			ans++;
			idx2++;
		}
	}
	
	cout << ans;
	
	return 0;
}
