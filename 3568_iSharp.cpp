#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s, form;

int main(){
	getline(cin, s);
	
	int s_size=s.size();
// form 
	for(int i=0; i<s_size; i++){
		if(s[i]!=' ') continue;
		form=s.substr(0, i);
		break;
	}
// vars, forms
	for(int i=1; i<s_size; i++){
		string vars, forms;
		if(s[i-1]==' '){
			int start=i;
			while(('a'<=s[i] && s[i]<='z') || ('A'<=s[i] && s[i]<='Z')) i++;
			vars=s.substr(start, i-start);

			start=i;
			while(s[i]!=',' && s[i]!=';') i++;
			reverse(s.begin()+start, s.begin()+i);
			forms=s.substr(start, i-start);
			
			int forms_size=forms.size();
			for(int i=0; i<forms_size; i++){
				if(forms[i]==']'){
					int tmp=forms[i];
					forms[i]=forms[i+1];
					forms[i+1]=tmp;
					i++;
				}
			}
		}
		else continue;

		cout << form+forms+" "+vars+";" << endl;		
	}
	
	return 0;
}
