#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321
using namespace std;

vector<int> bricks, a;
int n, k, ans=INF, bricks_size;
bool visit[30];

int calc(){
	int ret=0;
	for(int i=0; i<k-1; i++){
		int add=n-bricks[a[i]];
		ret+=add;
	}
		
	return ret; 
}

void comb(int depth, int start){
	if(depth==k-1){
		int tmp=calc();
		if(ans>tmp) ans=tmp;

		return ;
	}

	for(int i=start; i<(bricks_size-1)-(k-1)+depth+1; i++){
		if(visit[i-1]) continue;

		a.push_back(i);
		visit[i]=true;
		comb(depth+1, i+1);
		visit[i]=false;
		a.pop_back();
	}
	
	return ;
} 


int solution(vector<int> bricks_, int n_, int k_) {
	bricks.assign(bricks_.begin(), bricks_.end()); n=n_; k=k_; //√ ±‚»≠
	bricks_size=bricks.size();
	
	comb(0, 1); 

    return ans;
}
