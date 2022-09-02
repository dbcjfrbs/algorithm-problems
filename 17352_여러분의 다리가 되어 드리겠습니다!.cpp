#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321
using namespace std;

int n, parent[300001];

int getParent(int x){
	if(parent[x]==x) return x; 
	return parent[x]=getParent(parent[x]);
}

void unionParent(int a, int b){
	a=getParent(a);
	b=getParent(b);
	
	if(a<b) parent[b]=a;
	else parent[a]=b;
	
	return ;
}

bool sameParent(int a, int b){
	a=getParent(a);
	b=getParent(b);	
	return a==b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	cin >> n;	
	for(int i=1; i<=n; i++) parent[i]=i;
	
	int a, b;
	for(int i=0; i<n-2; i++){
		cin >> a >> b;
		
		unionParent(a, b);
	}
	
	for(int i=2; i<=n; i++){
		if(!sameParent(1, i)){
			cout << 1 << ' ' << i;
			return 0;
		}
	}	
}
