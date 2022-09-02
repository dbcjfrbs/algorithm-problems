#include <iostream>
#include <string>
using namespace std;

int tc;

string binary(int n){
	string ret="";
	do{
		ret+=to_string(n%2);
		n/=2;
	}while(n);
	
	return ret;	
}

void solve(string s){
	int s_size=s.size();
	for(int i=0; i<s_size; i++){
		if(s[i]=='1') cout << i << ' ';
	}
	cout << '\n';	
	return ;
}

int main(){
	cin >> tc;
	int n;
	while(tc--){
		cin >> n;		

		string s=binary(n);
		solve(s);
	}
	
	return 0;
}
