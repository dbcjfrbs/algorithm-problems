#include <iostream>
using namespace std;

int main(){
	long long s;
	cin >> s;
	
	int cnt=1;
	while(s-cnt>=0){
		s-=cnt;
		cnt++;
	}
	 
	cout << --cnt;
	return 0;
} 
