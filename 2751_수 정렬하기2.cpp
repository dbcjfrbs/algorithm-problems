#include <stdio.h>
using namespace std;
int n;
int a[2000001];

int main(){
	scanf("%d", &n);
	
	int t;
	for(int i=0; i<n; i++){
		scanf("%d", &t);
		a[t+1000000]++;
	}
	for(int i=0; i<=2000000; i++){
		if(a[i]) printf("%d\n", i-1000000);
	}
	
	return 0;
}
