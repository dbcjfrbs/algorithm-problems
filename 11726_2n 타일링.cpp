#include <iostream>
using namespace std;

int d[1001];
int dp(int x){
	if(d[x]!=0) return d[x];
	return d[x]=(dp(x-1)+dp(x-2))%10007;
}

int main(){
	int n;
	cin >> n;
	
	d[1]=1, d[2]=2;
	cout << dp(n);
	
	return 0;
}
