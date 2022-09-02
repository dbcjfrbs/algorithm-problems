#include <iostream>
using namespace std;

int n, m, arr[100000], Max;

bool isPossible(int x){
	int cnt=1, money=x;
	for(int i=0; i<n; i++){
		if(money>=arr[i]){
			money-=arr[i];
			continue;
		}
		
		money=x-arr[i];
		cnt++;
	}
	
	return cnt<=m;
}

int binarySearch(){ 	
	int s=Max, e=1000000000, mid;
	while(s!=e){
		cout << s << ' ' << e << '\n';
		mid=(s+e)/2;
		if(isPossible(mid)){
			e=mid;
			continue;
		}
		s=mid+1;
	}
	
	return s;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		if(Max<arr[i]) Max=arr[i];
	}	
	
	cout << binarySearch();	
	
	return 0;
}
