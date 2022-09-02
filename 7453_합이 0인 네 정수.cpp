#include <iostream>
#include <algorithm>
#define MAX 16000001
using namespace std;

int n, a[4001], b[4001], c[4001], d[4001];
int arr1[MAX], arr2[MAX];
long long ans;

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
// 정렬 
	sort(arr1, arr1+tmp);
	sort(arr2, arr2+tmp);	
	
// 투포인터 계산
	int idx1=tmp-1, idx2=0;
	while(idx1!=-1 && idx2!=tmp){
		if(arr1[idx1]+arr2[idx2]>0) idx1--;
		else if(arr1[idx1]+arr2[idx2]<0) idx2++;
		else{
			long long same1=1, same2=1;
			while(arr1[idx1--]==arr1[idx1] && idx1!=-1) same1+=1;
			while(arr2[idx2++]==arr2[idx2] && idx2!=tmp) same2+=1;
			
			ans+=same1 * same2;
		}
	}
	
	cout << ans;
	
	return 0;
}
