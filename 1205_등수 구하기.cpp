#include <iostream>
using namespace std;
int n, x, p;
int score[51];

int main(){
	cin >> n >> x >> p;
	for(int i=1; i<=n; i++)
		cin >> score[i];

	if(!n){
		cout << 1;
		return 0;
	}

	for(int i=1; i<=n; i++){
		if(x>score[i]){
			cout << i;
			return 0;
		}
		if(x==score[i])
			for(int j=i; j<=n; j++){
				if(x!=score[j]){
					cout << i;
					return 0;
				}
				if(j==n && x==score[n]){
					if(n<p) cout << i;
					else cout << -1;
					return 0;
				}
			}
	}
	
	if(n<p) cout << n+1;
	else cout << -1;

	return 0;
}
