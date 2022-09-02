#include <iostream>
#include <string>
using namespace std;

string s;

int main(){
	cin >> s;
	
	string ret;
	for(int i=0; i<s.size(); i++){
		if('A'<=s[i] && s[i]<='C'){
			char tmp=s[i];
			tmp+=23;
			ret+=tmp;	
		}	
		else ret+=s[i]-3;
	}	
	
	cout << ret;
	
	return 0;
}

int main(){
	cin >> s;
	
	string ret;
	for(int i=0; i<s.size(); i++){
		if(s[i]-3<65) s[i]+=26;
		ret+=s[i]-3;
	}
	
	cout << ret;
	
	return 0;
}
