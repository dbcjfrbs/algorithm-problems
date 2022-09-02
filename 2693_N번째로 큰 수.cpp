#include <iostream>
using namespace std;

int tc, a[1000];

int main(){
	int tc;
	cin >> tc;
	int a[10];
	while(tc--){
		for(int i=0; i<10; i++) cin >> a[i];
		
		for(int i=0; i<9; i++){
			for(int j=i; j<10; j++){
				 if(a[i]<a[j]){
				 	int tmp=a[i];
				 	a[i]=a[j];
				 	a[j]=tmp;
				 }
			}
		}
		
		cout << a[2] << '\n';
	}
	
	return 0;
}
