#include <iostream>
#include <string> 
#include <algorithm>
using namespace std;

int n;
string s, e;

void on(int i, string &ss){
	for(int x=i; x<=i+2; x++){
		if(x>=n || x<0) continue;
		if(ss[x]=='0') ss[x]='1';
		else ss[x]='0';		
	}
	return ;
}

int solve(int x, int cnt){ // 시작지점 
	string ss=s;
	for(int i=x; i<n-1; i++){
		if(i==-1){
			on(i, ss);
			cnt++;
			continue;
		}
		if(ss[i]==e[i]) continue;
		on(i, ss);
		cnt++;
	}

	if(ss[n-1]==e[n-1]) return cnt;
	return -1;	
}

int main(){
	cin >> n >> s >> e;
	
	int a, b;
	a=solve(-1, 0);
	b=solve(0, 0);
	
	if(a==-1 && b==-1) cout << -1;
	else if(a!=-1 && b!=-1) cout << min(a, b);
	else cout << max(a, b);
	
	return 0;
} 
