#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;

int bfs(int x){
	int q[n]={0,};
	int f=-1, r=-1;
	int check[n]={0, };
	
	q[++r]=x;
	check[x]=1;
	
	while(f!=r){
		int tx=q[++f], jump_max=arr[tx];
		for(int i=1; i<=jump_max; i++){
			int nx=tx+i;
			if(nx>=n || check[nx]!=0) continue;
			
			q[++r]=nx;
			check[nx]=check[tx]+1;
		}
	}
	
	int ret=check[n-1]-1;
	if(check[n-1]==0) return -1;
	return ret;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	
	cout << bfs(0);
		
	return 0;
}
