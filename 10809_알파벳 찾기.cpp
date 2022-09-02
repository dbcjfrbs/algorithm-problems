#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	for(char ch='a'; ch<='z'; ch++){
		for(int i=0; i<s.size(); i++){
			if(ch==s[i]){
				cout << i << ' ';
				break;
			}
			if(i==s.size()-1) cout << -1 << ' ';
		}
	}	
	
	return 0;
}
