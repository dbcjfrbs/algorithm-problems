#include <iostream>
using namespace std;

int N;

int cycle(int n){ // 1cycle 후 값 리턴 
	int a, b, new_n; // 차례대로 10, 1 자리수의 값 
	if(n>=10){
		a=n/10;
		b=n%10;
	}	
	else{
		a=0;
		b=n;
	}
	new_n=a+b;

	int c, d;	
	if(new_n>=10){
		c=new_n/10;
		d=new_n%10;
	}	
	else{
		c=0;
		d=new_n;
	}
	
	return 10*b+d;
}	 

int main(){
	cin >> N;
	
	int t=N, cnt=0;
	while(1){
		t=cycle(t);
		cnt++;
		if(t==N){
			cout << cnt;
			return 0;
		}
	}
} 
