#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, k, time;
vector<int> v[1000];

void init(){
	cin >> n >> k;
	for(int i=0; i<2*n; i++){
		int tmp;
		cin >> tmp;
		v[i].push_back(tmp);
		v[i].push_back(0);
	}
	return ;
}

void cycle(){
	for(int i=0; i<n; i++){
		cout << 1;
		if(v[i%(2*n)][1]==1 && v[(i+1)%(2*n)][1]==0){
			if(v[(i+1)%(2*n)][0]==0) continue;
						
			if(--v[(i+1)%(2*n)][0]==0) k--;
			
			v[i%(2*n)][1]=0;	
			v[(i+1)%(2*n)][1]=1;

			i++;
		}
	}
	
	int tmp=2*n-time;
	int start=tmp < 0 ? (tmp+(2*n))%(2*n) : tmp%(2*n);
	if(v[start][0]>0){
		v[start][1]=1;
		if(--v[start][0]==0) k--;
	}
	
	return ;
}

int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);

	init();

	while(k>0){
		time++;
		cycle();
	}
	
	cout << time;
	return 0;
}
