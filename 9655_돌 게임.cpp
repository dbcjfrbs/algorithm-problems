#include <iostream>
using namespace std;

int n, d[1001];

int main(){
	cin >> n;
	
	d[1]=1;	d[2]=0;	d[3]=1;
	for(int i=4; i<=n; i++){
		if(d[i-1]==0) d[i]=1;
		else if(d[i-3]==0) d[i]=1;
		else d[i]=0;
	}
	
	if(d[n]==1) cout << "SK";
	else cout << "CY";
	
	return 0;
}
