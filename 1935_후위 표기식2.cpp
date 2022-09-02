#include <iostream>
#include <string>
#include <map>
#include <math.h>
using namespace std;

int n;
char s[200];
map<char, int> table;
double stk[200];
int top=-1;

int main(){
	cin >> n;
	cin >> s;
	for(int i=0; i<n; i++) cin >> table['A'+i];
	
	for(int i=0; s[i]!='\0'; i++){
		if('A'<=s[i] && s[i]<='Z') stk[++top]=table[s[i]];
		else{
			if(s[i]=='*') stk[top-1]*=stk[top];
			else if(s[i]=='/') stk[top-1]/=stk[top];
			else if(s[i]=='+') stk[top-1]+=stk[top];
			else stk[top-1]-=stk[top];
	
			top--;
		}		
	}
	
	cout << fixed;
	cout.precision(2);
	cout << stk[top];
	
	return 0;
}
