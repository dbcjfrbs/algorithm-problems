#include <iostream>
#define MAX 100000000
using namespace std;

int a, b;

int dfs(long long x, int cnt){
	if(x==b) return cnt;
	else if(x>b) return MAX;
	
	int tmp1=dfs(2*x, cnt+1);	
	int tmp2=dfs(x*10+1, cnt+1);
	if(tmp1<tmp2) return tmp1;
	else return tmp2;	
}

int main(){
	cin >> a >> b;
	
	int ans=dfs(a, 1);
	if(ans==MAX) cout << -1;
	else cout << ans;
	
	return 0;
}
