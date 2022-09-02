#include <iostream>
using namespace std;

int n, arr[2][1600000], d[1600000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> n;
	for(int i=1; i<=n; i++) cin >> arr[0][i] >> arr[1][i];

	d[0]=0;
	for(int i=1; i<=n+1; i++){
		int t=arr[0][i], p=arr[1][i];
		if(d[i]<d[i-1]) d[i]=d[i-1];  
		if(i+t<=n+1 && d[i+t]<d[i]+p) d[i+t]=d[i]+p;
	}
	
	cout << d[n+1] << '\n';
	return 0;
}
