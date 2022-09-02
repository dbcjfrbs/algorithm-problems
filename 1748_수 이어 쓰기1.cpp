#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int d[10]; // 이어쓰기 했을 때 자릿수 갯수 

int main(){
	int n;
	cin >> n; 
	
	for(int i=1; i<=9; i++){
		d[i]=i*(pow(10, i)-pow(10, i-1));
	}
	
	string s=to_string(n);
	int digit=s.size(), remain_cnt=n-pow(10, digit-1)+1;
	
	int ans=0;
	for(int i=1; i<=digit-1; i++){
		ans+=d[i];
	}
	
	ans+=remain_cnt*digit;
	cout << ans;	
	
	return 0;
}
