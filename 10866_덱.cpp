#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define MAX 100000
typedef long long ll;
using namespace std;

int n, deq[MAX], f=MAX/2, r=f-1;

void solve(string s){
	if(s.substr(0, 4)=="push"){
		if(s.substr(5, 4)=="back"){
			deq[++r]=stoi(s.substr(10));
		}
		else{
			deq[--f]=stoi(s.substr(11));
		}
	}
	else if(s.substr(0, 3)=="pop"){
		if(s.substr(4, 4)=="back"){
			if(r<f) cout << -1;
			else cout << deq[r--];
		}
		else{
			if(r<f) cout << -1;
			else cout << deq[f++];
		}
		cout << '\n';
	}
	else if(s=="size") cout << r-f+1 << '\n';
	else if(s=="empty"){
		if(r>=f) cout << 0;
		else cout << 1;
		cout << '\n';
	}
	else if(s=="front"){
		if(r<f) cout << -1;
		else cout << deq[f];
		cout << '\n';
	}
	else{
		if(r<f) cout << -1;
		else cout << deq[r];		
		cout << '\n';
	}
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	cin >> n;
	cin.ignore();
	string s;
	while(n--){
		getline(cin, s);
		solve(s);
	}
	
	return 0;
}
