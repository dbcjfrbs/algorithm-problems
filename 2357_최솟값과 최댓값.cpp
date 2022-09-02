#include <iostream>
#define MAX 100000
using namespace std;
int n, m;
int a[MAX];
struct PAIR{
	int max, min;
};
PAIR tree[4*MAX+1];

PAIR init(int start, int end, int node){
	if(start==end) return tree[node]={a[start], a[start]};

	int mid=(start+end)/2;
	PAIR left, right;
	left=init(start, mid, node*2);
	right=init(mid+1, end, node*2+1);

	if(left.max>=right.max) tree[node].max=left.max;
	else tree[node].max=right.max;
	if(left.min>=right.min) tree[node].min=right.min;	
	else tree[node].min=left.min;

	return tree[node];
}

PAIR ans(int start, int end, int node, int left, int right){
	if(right-1<start || end<left-1) return {1, 1000000000};
	if(left-1<=start && end<=right-1) return tree[node];
	
	int mid=(start+end)/2;
	PAIR L, R, RES;
	L=ans(start, mid, node*2, left, right);
	R=ans(mid+1, end, node*2+1, left, right);

	if(L.max>=R.max) RES.max=L.max;
	else RES.max=R.max; 	
	if(L.min>=R.min) RES.min=R.min;
	else RES.min=L.min;
	
	return RES;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); // 다시보기 

	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	init(0, n-1, 1);
	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b;
		
		PAIR p=ans(0, n-1, 1, a, b);
		cout << p.min << " " << p.max << "\n";		
	}
	
	return 0;
}
