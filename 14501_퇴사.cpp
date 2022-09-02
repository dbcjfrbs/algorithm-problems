#include <iostream>
using namespace std;

int n, t[16], p[16], d[16];

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> t[i] >> p[i];
	}
	
	for(int i=1; i<=n+1; i++){
		if(d[i]<d[i-1]) d[i]=d[i-1];
		if(d[i+t[i]]<d[i]+p[i] && i+t[i]<=n+1) d[i+t[i]]=d[i]+p[i];
	}
	
	cout << d[n+1];
	
	return 0;
}
