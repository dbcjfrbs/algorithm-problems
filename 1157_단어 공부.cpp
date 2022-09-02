#include <iostream>
#include <string>
using namespace std;

int main(){
	int count[127]={0};
	string s;

	cin >> s;

	int size=s.size();
	for(int i=0; i<size; i++){
		if('a'<=s[i] && s[i]<='z') count[s[i]-32]++;
		else count[s[i]]++;
	}
	
	int max=0, idx, max_cnt=1;
	for(int i=0; i<128; i++){
		if(max<count[i]){
			max=count[i];
			idx=i;
			max_cnt=1;
		}
		else if(max==count[i]) max_cnt++;
	}
	
	char ans=idx;
	if(max_cnt>1) cout << '?';
	else cout << ans;
	
	return 0;
}



