#include <iostream>
using namespace std;

int n;

int main(){
	cin >> n;
	
	int order=0, layer=1;
	while(1){
		if(n-layer>0) n-=layer;
		else{
			order=n;
			break;
		}
		
		layer++; 
	}	
	
	int sum=layer+1;
	
	if(layer%2==0) cout << order << '/' << sum-order; 
	else cout << sum-order << '/' << order;
	return 0;
}
