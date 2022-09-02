#include <iostream>
#define MAX 11
using namespace std;

int n, seq[MAX], a[MAX];
int Operator[4];
int Max=-1000000001, Min=1000000001;

void solve(int k, int sum){
	if(k==n){
		if(sum>Max) Max=sum;
		if(sum<Min) Min=sum;
		return ;
	}
	
	for(int i=0; i<4; i++){
		if(Operator[i]>0){
			Operator[i]--;
			if(i==0) solve(k+1, sum+seq[k]);
			else if(i==1) solve(k+1, sum-seq[k]);
			else if(i==2) solve(k+1, sum*seq[k]);
			else solve(k+1, sum/seq[k]);
			Operator[i]++;		
		}
	}
	
	return ;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> seq[i];
	for(int i=0; i<4; i++) cin >> Operator[i];
	
	solve(1, seq[0]);
	
	cout << Max << '\n' << Min;
	return 0;
}
