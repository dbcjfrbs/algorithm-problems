#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math.h>

typedef long long ll;
using namespace std;

int n;
map<string, int> arr;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	string str;
	for(int i=0; i<n; i++){
		cin >> str;
		arr[str]++;
	}
	
	int MAX=0;
	for(map<string, int>::iterator iter=arr.begin(); iter!=arr.end(); iter++){
		if(MAX<(iter->second)) MAX=iter->second; 		
	}

	vector<string> ans_v;
	for(map<string, int>::iterator iter=arr.begin(); iter!=arr.end(); iter++){
		if(MAX==(iter->second)) ans_v.push_back(iter->first); 		
	}
	
	ll ans=pow(2, 62);
	int len=ans_v.size();
	for(int i=0; i<len; i++){
		if(ans>stoll(ans_v[i])) ans=stoll(ans_v[i]); 
	}
	
	cout << ans;
	
	return 0;
}
