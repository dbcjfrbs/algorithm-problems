#include <iostream>
using namespace std;

int n;
long long d[81];

long long dp(int x){
	if(x==1 || x==2) return 1;
	if(d[x]!=0) return d[x];
	return d[x]=dp(x-1)+dp(x-2);
}

int main(){
	cin >> n;
	
	d[1]=1;	d[2]=1; d[3]=2;
	dp(n+1);
	long long ans=d[n+1]*2+d[n]*2;
	cout << ans;
	return 0;
}
