#include <iostream>
#define MAX 10001
using namespace std;
int visit[MAX];

void solve(int x){
	int nx=x, remain;
	do{
		remain=x%10;
		nx+=remain;

		x/=10;
	}while(x);

	if(nx>10000) return ;
	visit[nx]=1;
	solve(nx);

	return ;
}

int main(){
	for(int i=1; i<=10000; i++){
		if(!visit[i]){
			solve(i);
			cout << i << endl;
		}
	}
	
	return 0;
}
