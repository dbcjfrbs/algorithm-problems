#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321
#include <map>
using namespace std;

int n, m;
map<int, bool> v;
bool check[100001];

void init(){
	cin >> n;
	int a;
	for(int i=0; i<n; i++){
		cin >> a;
		v[a]=true;
	}
	
	cin >> m;
	int b;
	for(int i=0; i<m; i++){
		cin >> b;
		if(v[b]==true) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();
	
	return 0;
}
