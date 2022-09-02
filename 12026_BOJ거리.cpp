#include <iostream>
#include <string>
#define INF 1000000000
using namespace std;

int n, ans=INF;
char ptrs[3]={'B', 'O', 'J'};
string block;

void dfs(int start, int val, int ptr){
	if(val>=ans) return ;
	
	int block_len=block.size();
	if(start==block_len-1 && val<ans){
		ans=val;
		return ;
	} 
	
	for(int i=start; i<block_len; i++){
		if(block[i]==ptrs[(ptr+1)%3]) dfs(i, val+(i-start)*(i-start), ptr+1);
	}
	
	return ;
}

int main(){
	cin >> n >> block;
		 
	dfs(0, 0, 0);
	if(ans==INF) cout << -1;
	else cout << ans;
	
	return 0;
}
