#include <iostream>
using namespace std;
// 12:00
int tc, h, w, n; 

int main(){
	cin >> tc;
	while(tc--){
		cin >> h >> w >> n;
		
		int order=(n-1)/h+1, floor=(n-1)%h+1;		
		cout << floor*100+order << '\n';
	}	
	
	return 0;
}
