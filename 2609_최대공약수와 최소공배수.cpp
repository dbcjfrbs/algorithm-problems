#include <iostream>
using namespace std;

int a, b;

int gcd(int a, int b){
	if(a>b) return gcd(a-b, b);
	else if(b>a) return gcd(b-a, a);
	else return a;
}

int main(){
	cin >> a >> b;
	int x=gcd(a, b);
	cout << x << endl << x * a/x * b/x;
	
	return 0;
}
