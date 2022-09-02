#include <iostream>
#include <algorithm>
using namespace std;

int n, seq[8], a[8], ans=0;
bool visit[8];

int Calc(){
	int ret=0;	
	for(int i=0; i<n-1; i++) ret+=abs(a[i]-a[i+1]);
	
	return ret;
}

void Dfs(int cnt){
	if(cnt==n){
		int tmp=Calc();
		if(ans<tmp) ans=tmp;
		
		return ;
	}
	
	for(int i=0; i<n; i++){
		if(visit[i]) continue;
		
		a[cnt]=seq[i];
		
		visit[i]=true;
		Dfs(cnt+1);
		visit[i]=false;	
	}
	
	return ;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> seq[i];
	
	Dfs(0);
	cout << ans;
	
	return 0;
}
