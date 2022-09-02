#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321
typedef long long ll;
using namespace std;

int n, m, arr[100000], tree[400004];

int init(int s, int e, int node){
	if(s==e) return tree[node]=arr[s];
	int mid=(s+e)/2;
	return tree[node]=min(init(s, mid, node*2), init(mid+1, e, node*2+1));
}

int findIndex(int s, int e, int node){
	if(s==e) return s;
	int mid=(s+e)/2;
	if(tree[node*2]==tree[node]) return findIndex(s, mid, node*2);
	else return findIndex(mid+1, e, node*2+1);
}

int update(int s, int e, int node, int idx, int val){
	if(s==e) {
		return tree[node]=val;
	} 
	
	int mid=(s+e)/2;
	if(idx<=mid) return tree[node]=min(update(s, mid, node*2, idx, val), tree[node*2+1]);
	else return tree[node]=min(tree[node*2], update(mid+1, e, node*2+1, idx, val));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	cin >> n;
	for(int i=1; i<=n; i++) cin >> arr[i];

	init(1, n, 1);
	
	cin >> m;
	for(int i=0; i<m; i++){
		int a, b, c;
		cin >> a;
		if(a==1){
			cin >> b >> c;
			update(1, n, 1, b, c);
		}
		else cout << findIndex(1, n, 1) << '\n';
	} 	
	
	return 0;
} 
