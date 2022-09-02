#include <iostream>
using namespace std;

int tc, n;
int d[100];

int f(int n){
	if(n==1) return d[1];
	if(n==2) return d[2];
	
	if(d[n]!=0) return d[n];
	
	return d[n]=f(n-1)+f(n-2);
}

int main(){
	d[1]=0; d[2]=1;
	
	cin >> tc;
	while(tc--){
		cin >> n;
		
		if(n==0) cout << 1 << ' ' << 0;
		else cout << f(n) << ' ' << f(n+1);
		cout << endl;
	}
		
	return 0;
}
