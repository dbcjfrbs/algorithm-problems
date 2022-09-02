#include <iostream>
#include <string>
using namespace std;

int tc; 

void print(string s){
	char stack[1001];
	int top=-1, s_size=s.size();
	
	for(int i=0; i<s_size; i++){
		if(s[i]==' ' || i==s_size-1){
			if(i==s_size-1) stack[++top]=s[i];
			
			while(top!=-1){
				cout << stack[top--];
			}
			cout << ' ';
		}
		else stack[++top]=s[i];
	}
}

int main(){
	cin >> tc;
	cin.ignore();

	string s;
	while(tc--){
		getline(cin, s);
		
		print(s);
		cout << '\n';
	}
		
	return 0;
}
