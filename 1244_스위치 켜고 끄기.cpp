#include <iostream>
using namespace std;

int n, arr[100], tc;

int main(){
	cin >> n;	
	for(int i=0; i<n; i++) cin >> arr[i];
	cin >> tc;
	
	while(tc--){
		int a, b;
		cin >> a >> b;
		if(a==1){
			int tmp=b-1;
			while(tmp<n){
				arr[tmp]=arr[tmp]==1 ? 0 : 1;
				tmp+=b;
			}
		}
		else{
			int t1=b-1, t2=b-1;
			arr[t1]=arr[t1]==1 ? 0 : 1;
			t1--;
			t2++;
			
			while(t1>=0 && t2<n && arr[t1]==arr[t2]){
				arr[t1]=arr[t1]==1 ? 0 : 1;
				arr[t2]=arr[t2]==1 ? 0 : 1;
				t1--;
				t2++;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		cout << arr[i] << ' ';
		if((i+1)%20==0) cout << '\n';
	}	
	return 0;
}
