#include <iostream>
#include <string>
using namespace std;

int my_strlen(char *s){
	int len=0;
	while(*s++) len++;
	
	return len;
}

int depth_count(char *s){
	int cnt=0;
	int max=0; 
	int len=my_strlen(s);

	for(int i=0; i<len; i++){
		if(s[i]=='['){
			cnt++;
			if(max<cnt) max=cnt;
		}
		else cnt--;
	}
	
	return max;
}

int main(){
	int tc;
	cin >> tc;
	cin.ignore();
	for(int i=0; i<tc; i++){
		char stack[150]="";
		int depth=0;
		cin.getline(stack, 150);
		
		depth=depth_count(stack);
	
		int ans=1;
		cout << (ans<<depth) << endl;	
	}	
	
	return 0;
} 
