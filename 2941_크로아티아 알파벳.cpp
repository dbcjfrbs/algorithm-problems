#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	int ans=0, i=0;
	while(i<s.size()){
		if(i<s.size()-1 && s.substr(i, 2)=="c=" || s.substr(i, 2)=="c-" || s.substr(i, 2)=="d-" 
		|| s.substr(i, 2)=="lj" || s.substr(i, 2)=="nj" || s.substr(i, 2)=="s=" || s.substr(i, 2)=="z=") i+=2;
		else if(i<s.size()-2 && s.substr(i, 3)=="dz=") i+=3;
		else i++;
		
		ans++;
	}
	
	cout << ans;
	
	return 0;
} 
