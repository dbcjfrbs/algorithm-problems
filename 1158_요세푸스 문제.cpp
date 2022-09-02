#include <iostream>
using namespace std;

int q[25000000]; // 최대 100MB
int f=-1, r=-1; // f : 큐 최앞단으로 pop 역할, r : 큐 최뒷단으로 insert 역할

int main(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; i++) q[++r]=i; // 큐에 전부 넣어줌 
		
	cout << '<';
	// (pop -> push) -> (pop ->push) -> pop 
	int tmp;
	while(n--){
		for(int i=0; i<k-1; i++){ 
			tmp=q[++f];
			q[++r]=tmp;
		}

		if(n==0) cout << q[++f];
		else cout << q[++f] << ", ";
	}
	cout << '>';
	
	return 0;
}
