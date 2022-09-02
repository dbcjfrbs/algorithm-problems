#include <iostream>
#include <string>
#include <stack> 
using namespace std;

int tc;

bool isVPS(string s){
	stack<int> stk;
	int s_size=s.size();
	for(int i=0; i<s_size; i++){
		if(s[i]=='(') stk.push('(');
		else{
			if(stk.empty()) return false;			
			stk.pop();
		}
	}
	
	if(!stk.empty()) return false;
	return true;
}

int main(){
	cin >> tc;
	string s;
	while(tc--){
		cin >> s;
		
		if(isVPS(s)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
		
	return 0;
}
