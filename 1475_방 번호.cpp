#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;

	int nums[10]={0}; 
	int sixNine=0, max=0;
	for(int i=0; i<s.size(); i++){
		nums[s[i]-'0']++;
//		cout << s[i]-'0';
		
		if(s[i]=='6' || s[i]=='9'){
			sixNine++;
			continue;
		}
		
		if(max<nums[s[i]-'0']) max=nums[s[i]-'0'];
	}

	sixNine = sixNine%2==0 ? sixNine/2 : sixNine/2+1;
	
	cout << sixNine << " " <<  max; 
	
	max = max < sixNine ? sixNine : max;	


	
	cout << max;
	
	return 0;
} 
