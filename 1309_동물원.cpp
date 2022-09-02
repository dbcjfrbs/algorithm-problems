#include <iostream>
using namespace std;

int d[100001][2];

int main(){
	int n;	
	cin >> n;
		
	d[1][0]=1, d[1][1]=2;
	for(int i=1; i<n; i++){
		d[i+1][0]=d[i][0]+d[i][1];
		d[i+1][1]=d[i][0]*2+d[i][1];
		d[i+1][0]%=9901;
		d[i+1][1]%=9901;
	}
	
	cout << (d[n][0]+d[n][1])%9901;
	return 0;
}
