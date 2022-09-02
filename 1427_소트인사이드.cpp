#include <iostream>
#include <algorithm>
using namespace std;

char num[11];

bool compare(int a, int b){
	if(a > b) return true;
	return false;
}

int main(){
	char *cp=num;
	int i=0;
	do{
		scanf("%c", cp+i);
	}while(num[i++]!='\n');
	
	sort(num, num+i-1, compare);
	
	for(int j=0; j<i; j++)
		printf("%c", num[j]);
	
	return 0;
}
