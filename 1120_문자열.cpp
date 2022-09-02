#include <iostream>
#include <string>
using namespace std;

string s1, s2;

int calc(string str1, string str2){
	int ret=0, size=str1.size();
	for(int i=0; i<size; i++){
		if(str1[i]==str2[i]) continue;
		ret++;
	}
	
	return ret;
}

int main(){
	cin >> s1 >> s2;
	
	int s1_size=s1.size(), s2_size=s2.size(), ans=s2_size;
	for(int i=0; i<s2_size-s1_size+1; i++){
		int dif=calc(s1, s2.substr(i, s1_size));
		if(ans>dif) ans=dif;
	}
	
	cout << ans;	
	return 0;
}
