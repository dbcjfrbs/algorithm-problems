#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321
using namespace std;

//vector<vector<int> > dice({{1, 6, 2, 5, 3, 4}, {9, 9, 1, 0, 7, 8}});
vector<vector<int> > dice({{0, 1, 5, 3, 9, 2}, {2, 1, 0, 4, 8, 7}, {6, 3, 4, 7, 6, 5}});

int dice_size, dice_comb[4], dice_perm[4];
bool arr[10000], perm_visit[4];

void perm2(int n, int depth, string val){
	if(depth==n){
		arr[stoi(val)]=true;
		return ;
	}	
	
	for(int i=0; i<6; i++){
		string s=val+to_string(dice[dice_perm[depth]][i]);
		perm2(n, depth+1, s);
	}
	
	return ;
	
}

void perm(int n, int depth){
	if(depth==n){
		perm2(n, 0, "");
		return ;
	}	
	
	for(int i=0; i<n; i++){
		if(perm_visit[i]) continue;
		dice_perm[depth]=dice_comb[i];
		
		perm_visit[i]=true;
		perm(n, depth+1);
		perm_visit[i]=false;
	}
	
	return ;
}

void comb(int n, int depth, int start){ // dice °í¸£±â 
	if(depth==n){
		perm(n, 0);
		return ;
	}	
	
	for(int i=start; i<dice_size-n+depth+1; i++){
		dice_comb[depth]=i;
		comb(n, depth+1, i+1);
	}
	
	return ;
}

int solution(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);		
	
	dice_size=dice.size();
	for(int i=1; i<=dice_size; i++){
		comb(i, 0, 0);
	}
	
	for(int i=1; i<10000; i++){
		if(!arr[i]){
			return i;
		}
	}	
}

int main(){
	cout << solution();
	
	return 0;
}
