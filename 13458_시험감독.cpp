#include <iostream>
#define MAX 1000000
using namespace std;

int n, a[MAX], b, c;
long long ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	cin >> b >> c;
	
	for(int i=0; i<n; i++){
		a[i]-=b;
		ans++;		
		if(a[i]<=0) continue;
		
		ans+=a[i]/c;
		if(a[i]%c>0) ans++; 
	}
	
	cout << ans;

	return 0;
}
