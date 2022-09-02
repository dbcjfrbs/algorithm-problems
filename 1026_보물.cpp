#include <iostream>
#include <algorithm> 
#define MAX 50
using namespace std;

int n, a[MAX], b[MAX];

bool compare(int i, int j){
	return i>j;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i];
	for(int i=0; i<n; i++)
		cin >> b[i];

	sort(b, b+n);
	sort(a, a+n, compare);

	int sum=0;
	for(int i=0; i<n; i++){
		sum+=a[i]*b[i];
	}
	
	cout << sum;
	
	return 0;
}
