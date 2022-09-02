#include <iostream>
using namespace std;

int d[11];

int solve(int x){
	if(x==1) return d[1]=1;
	if(x==2) return d[2]=2;
	if(x==3) return d[3]=4;

	if(d[x]!=0) return d[x];
	return d[x]=solve(x-1)+solve(x-2)+solve(x-3);
}

int main(){
	int tc, n;
	cin >> tc;
	while(tc--){
		cin >> n;
		cout << solve(n) << endl;
	}
		
	return 0;
} 
