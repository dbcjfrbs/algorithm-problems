#include <iostream>
using namespace std;
int n, m;
int seq[10000];
int f=0, r=0;
int ans=0;

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		int t; cin >> t;
		seq[i]=t;
	}
	
	int sum=seq[r];
	while(r!=n){
		if(sum>=m){
			if(sum==m) ans++;
			sum-=seq[f++];
		}
		else sum+=seq[++r];
	}
	cout << ans;
	
	return 0;
}
