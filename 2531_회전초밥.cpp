#include <iostream>
using namespace std;

int n, d, k, c, arr[30000], check[30001], kinds, ans;

void init(){
	cin >> n >> d >> k >> c;
	for(int i=0; i<n; i++){
		cin >> arr[i];

		if(i<k){
			if(check[arr[i]]==0) kinds++;
			check[arr[i]]++;		
		}
	}

	return ;
}

int main(){
	init();
	
	ans=kinds;
	for(int i=0; i<n; i++){
		if(--check[arr[i]]==0) kinds--;
		if(check[arr[(k+i)%n]]==0) kinds++;
		check[arr[(k+i)%n]]++;
		
		if(check[c]==0){
			if(ans<kinds+1) ans=kinds+1;
		}
		if(ans<kinds){
			ans=kinds;			
		}
	}
	
	cout << ans;
	return 0;
}
