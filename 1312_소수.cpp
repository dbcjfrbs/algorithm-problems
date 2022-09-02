#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int a, b, n;
	cin >> a >> b >> n;
	
	int ret;
	while(n--){
		if(a>=b) a%=b;
		a*=10;
		ret=a/b;
	}

	cout << ret;
	return 0;
}
