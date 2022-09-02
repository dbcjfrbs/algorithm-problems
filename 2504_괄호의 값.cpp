#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s;
int ans;

int main(){
	cin >> s;
	
	stack<char> st;
	int t=1;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='('){
			t*=2;
			st.push('(');
		}
		else if(s[i]=='['){
			t*=3;
			st.push('[');
		}
		else if(s[i]==')'){
			if(st.empty() || st.top()=='['){
				cout << 0;
				return 0;

			}
			
			if(s[i-1]=='('){
				ans+=t;
				t/=2;
				st.pop();
			}
			else{
				t/=2;
				st.pop();
			}
		}
		else{
			if(st.empty() || st.top()=='('){
				cout << 0;
				return 0;

			}
			
			if(s[i-1]=='['){
				ans+=t;
				t/=3;
				st.pop();
			}
			else{
				t/=3;
				st.pop();
			}
		}
	}
	
	if(!st.empty()) cout << 0;
	else cout << ans;
	
	return 0;
}
