#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long n, m, sum;
vector<long long> height, diff;

int main(){
	cin >> n >> m;
	int tmp;
	for(int i=0; i<n; i++){
		cin >> tmp;
		height.push_back(tmp);
	}
	sort(height.begin(), height.end());
	
	for(int i=n-1; i>0; i--) diff.push_back(height[i]-height[i-1]);
	diff.push_back(height[0]); 
	
	int i, ans=height[n-1];
	for(i=0; i<n; i++){
		sum+=diff[i]*(i+1);
		ans-=diff[i];
		if(sum>=m) break;
	} 
	
	while(sum>=m){
		sum-=i+1;
		ans++;
	}

	cout << --ans;
	
	return 0;
}
