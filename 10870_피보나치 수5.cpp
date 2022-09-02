#include <iostream>
using namespace std;

int d[21];

int dp(int x){
	if(x==0) return d[0];
	if(x==1) return d[1]=1;
	if(d[x]!=0) return d[x];
	
	return d[x]=dp(x-1)+dp(x-2);
}

int main(){
	int n;
	cin >> n;
	cout << dp(n);
	
	return 0;
}
