#include <iostream>
using namespace std;

int h, w, ans;
int arr[500];

int main(){
	cin >> h >> w;
	for(int i=0; i<w; i++) cin >> arr[i];
	
	for(int j=1; j<=h; j++){
		bool s=false, e=true;
		int cnt=0;
		for(int i=0; i<w; i++){
			if(s && arr[i]<j) e=false;
			else if(s && arr[i]>=j) e=true;
			
			if(arr[i]>=j) s=true;
			else if(!s) continue;
			
	
			if(!e) cnt++;
			else{
				ans+=cnt;
				cnt=0;
			} 
		}
	}
	
	cout << ans;
	return 0;
}
