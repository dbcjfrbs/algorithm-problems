#include <iostream>
using namespace std;

int n, ans;
int codes[4]={1, 5, 10, 50};
bool nums[1001];

void Comb(int depth, int start, int sum){
	if(depth==n){
		if(!nums[sum]){
			nums[sum]=true;
			ans++;
		}

		return ;
	}
	
	for(int i=start; i<4; i++){
		Comb(depth+1, i, sum+codes[i]);
	}	
	
	return ;
}

int main(){
	cin >> n;
	
	Comb(0, 0, 0);
	cout << ans;
	
	return 0;
}
