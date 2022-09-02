#include <iostream>
using namespace std;
int s[100000];

int main(){
	int T;	cin >> T;
	for(int z=0; z<T; z++){
		int N;
		cin >> N;
		for(int i=0; i<N; i++){
			int idx;
			cin >> idx >> s[idx];
		}		

		int ans=0;
		for(int i=1; i<N; i++){
		    if(s[i]<s[i+1]){
		        s[i+1]=s[i];
		        ans++;
		    }
		}

		cout << N-ans << endl;
	}

	return 0;

}
