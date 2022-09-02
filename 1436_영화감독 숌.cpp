#include <iostream>
#include <string>
using namespace std;

int n;

bool is666(int x){
	string s=to_string(x);
	int size=s.size(), cnt_six=0;
	for(int i=0; i<size; i++){
		if(s[i]=='6') cnt_six++;
		else cnt_six=0;

		if(cnt_six==3) return true;
	}
	
	return false;
}

int main(){
	cin >> n;
	
	int cnt=0, x=1;
	while(1){
		if(is666(x)) cnt++;
		if(cnt==n) break; 
		x++;
	}	
	
	cout << x;
	return 0;
}
