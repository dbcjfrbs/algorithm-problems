#include <iostream>
#include <string>
using namespace std;

int s;
string str;
char hori[3][10]={
	{'-', ' ', '-', '-', ' ', '-', '-', '-', '-', '-'},
	{' ', ' ', '-', '-', '-', '-', '-', ' ', '-', '-'},
	{'-', ' ', '-', '-', ' ', '-', '-', ' ', '-', '-'}
};

char vert[2][10][2]={
	{{'|',  '|'}, {' ',  '|'}, {' ',  '|'}, {' ',  '|'}, {'|',  '|'}, {'|',  ' '}, {'|',  ' '}, {' ',  '|'}, {'|',  '|'}, {'|',  '|'}},
	{{'|',  '|'}, {' ',  '|'}, {'|',  ' '}, {' ',  '|'}, {' ',  '|'}, {' ',  '|'}, {'|',  '|'}, {' ',  '|'}, {'|',  '|'}, {' ',  '|'}}
};

void Hori(int loc){
	for(int i=0; i<str.size(); i++){
		cout << ' ';
		for(int j=0; j<s; j++) cout << hori[loc][str[i]-'0'];
		cout << "  ";
	}
	cout << '\n';
	
	return ;
}

void Vert(int loc){
	for(int j=0; j<s; j++){
		for(int i=0; i<str.size(); i++){
			cout << vert[loc][str[i]-'0'][0];
			for(int k=0; k<s; k++) cout << ' ';
			cout << vert[loc][str[i]-'0'][1];
			cout << ' ';
		}
		cout << '\n';	
	}
	
	return ;
}

int main(){
	cin >> s >> str;
	Hori(0);
	Vert(0);	
	Hori(1);
	Vert(1);	
	Hori(2);
	
	return 0;
}
