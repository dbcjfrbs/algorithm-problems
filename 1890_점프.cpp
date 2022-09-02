#include <iostream>
#define MAX 100
using namespace std;

int n, map[MAX][MAX];
long long d[MAX][MAX];

int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) cin >> map[i][j];
	
	d[0][0]=1;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(d[i][j]==0 || map[i][j]==0) continue;
			
			int val=map[i][j];
			int right=j+val;
			
			if(right<n) d[i][right]+=d[i][j];
			if(down<n) d[down][j]+=d[i][j];
		}
	}
		
	cout << d[n-1][n-1];
		
	return 0;
}
