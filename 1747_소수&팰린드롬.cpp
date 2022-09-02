#include <iostream>
using namespace std;
int N;
char str[10]="";

int strlen(char a[]){
	int cnt=0;
	
	while(a[cnt]!='\0'){
		cnt++;
	}
	
	return cnt;
}

void itoa(int a){
	int b;
	
	int t=0;
	while(a){
		b=a%10;
		a/=10;
		
		str[t++]=b+'0';
	}
	
	int tmp;
	for(int i=0; i<t/2; i++){
		tmp=str[i];
		str[i]=str[t-i-1];
		str[t-i-1]=tmp;	
	
	}
	
	return ;
}

bool isprime(int n){
	for(int i=2; i*i<=n; i++){
		if(n%i==0) return 0;
	}
	return 1;
}

bool ispal(char str[]){
	int len=strlen(str);
	
	if(len==1) return 1;
	for(int i=0; i<len/2; i++){
		if(str[i]!=str[len-1-i]) return 0;
		if(i==len/2-1) return 1;
	}	
}

int main(){
	cin >> N;

//	itoa(N);
	while(1){
		if(N==1 || N==2) {
			cout << 2;
			break;	
		}
		
		if(isprime(N)==1){
			itoa(N);
			if(ispal(str)==1){
				cout << N;
				break;
			}
		}		
	
		N++;
	}

	return 0;
}
