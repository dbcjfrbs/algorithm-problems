#include <iostream>
using namespace std;

int n;

bool isPrime(int x){
	if(x==1) return false;
	for(int i=2; i*i<=x; i++)
		if(x%i==0) return false;
	return true;
}

void Select(int val, int cnt){
	if(cnt==0){
		if(isPrime(val)) cout << val << '\n';
		return ;
	}
	
	for(int i=0; i<=9; i++){
		if(cnt==n && i==0) continue;
		if(isPrime(val*10+i)) Select(val*10+i, cnt-1);
	}
	
	return ;
}

int main(){
	cin >> n;
	Select(0, n);
	
	return 0;
}
