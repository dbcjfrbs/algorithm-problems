#include <iostream>
#include <string>
using namespace std;

int n, stack[10000], top=-1;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	cin.ignore();
	
	string s;
	while(n--){
		getline(cin, s);
		if(s.substr(0, 3)=="pus"){
			string tmp=s.substr(5);
			stack[++top]=stoi(tmp);
		}
		else if(s.substr(0, 3)=="pop"){
			if(top==-1) cout << -1 << endl;
			else cout << stack[top--] << endl;
		}
		else if(s.substr(0, 3)=="siz"){
			cout << top+1 << endl;
		}
		else if(s.substr(0, 3)=="emp"){
			if(top==-1) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else{
			if(top==-1) cout << -1 << endl;
			else cout << stack[top] << endl;
		}		
	}	
	
	return 0;
}
