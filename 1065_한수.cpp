#include <iostream>
using namespace std;
int a[3]={1, 0, 0};

int f(int n){
	int cnt=0;
	
	for(int x=1; x<=n; x++){
		if(x<100){
			cnt++;
			continue;
		}
		if(x==100 || x==1000) continue;
		
		a[2]++;
		if(a[2]==10){
			a[1]++;
			a[2]=0;

			if(a[1]==10){
				a[0]++;
				a[1]=0;
			}
		}
		
		if(a[1]-a[2]==a[0]-a[1]) cnt++;	
	}
	
	return cnt;
}

int main(){
	int n;
	cin >> n;
	cout << f(n);
	
	return 0;
} 
