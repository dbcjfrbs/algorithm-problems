#include <iostream>
#include <string>
using namespace std;

int n;
string s, ans;
string code[10]={
	"111111000111111", "1111100000", "101111010111101", "101011010111111", "111000010011111",
	"111011010110111", "111111010110111", "100001000011111", "111111010111111", "111011010111111"
};

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		char c;
		cin >> c;
		if(c=='#') s+='1';
		else s+='0';
	}
	int width=n/5;
	
	string cols="";
	for(int i=0; i<width; i++){
		string col="";
		for(int j=0; j<n; j+=width){
			col+=s[i+j];
		}
// ���� ������ ��
		if(cols=="" && col=="00000") continue;

		cols+=col;
// 1�� ��Ÿ���� ��
		if(cols=="1111100000" || (cols=="11111" && i==width-1)){
			ans=ans+'1';
			cols="";
			continue;	
		}
// 15�ڸ��� ä������ �� 
		if(cols.size()==15){
			for(int k=0; k<10; k++){
				char add='0'+k;
				if(cols==code[k]) ans=ans+add;
			}
			
			cols="";			
		}
	}
	
	cout << ans;
	
	return 0;
}
