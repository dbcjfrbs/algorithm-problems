#include <iostream>
using namespace std;

int q[25000000]; // �ִ� 100MB
int f=-1, r=-1; // f : ť �־մ����� pop ����, r : ť �ֵ޴����� insert ����

int main(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; i++) q[++r]=i; // ť�� ���� �־��� 
		
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
