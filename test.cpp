#include <iostream>
using namespace std;
int n, x, p;
int score[51];

int main(){
	cin >> n >> x >> p;
	for(int i=1; i<=n; i++){
		cin >> score[i];
	}

	if(!n){
		cout << 1;
		return 0;
	}

	for(int i=1; i<=n; i++){
		if(x>=score[i] && i!=n){
			cout << i;
			return 0;
		}
		if(i==n && x>score[n]){
			cout << n;
			return 0;
		}
		if(i==n && x=score[n]){
			cout << -1; 
			return 0;
		}
	}
	
	cout << -1;
	return 0;
}
