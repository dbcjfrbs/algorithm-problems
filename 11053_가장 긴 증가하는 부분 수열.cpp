#include <iostream>
using namespace std;

int n, arr[1000], ans;
int d[1000]; //�ش� �ε����� ���ڸ� ������ ���� �κ� ������ �ִ� ����  

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	
	d[0]=1;
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(arr[i]>arr[j] && d[i]<=d[j]){
				d[i]=d[j]+1;
			}
		}
		
		if(d[i]==0) d[i]=1;
	} 
	
	for(int i=0; i<n; i++){
		if(ans<d[i]) ans=d[i];
	}
	
	cout << ans;
	return 0;
}

