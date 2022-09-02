#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321

typedef long long ll;
using namespace std;

ll n, k, s=1, e;
vector<ll> v, anss;

void init(){
	cin >> k >> n;
	ll t, sum=0;
	for(int i=0; i<k; i++){
		cin >> t;
		v.push_back(t);
		sum+=t;
	}	
	
	e=sum/n;
	return ;
}

void binarySearch(ll start, ll End){
	if(start==End) return ;
	
	ll cnt=0, mid=(start+End)/2;
	for(int i=0; i<k; i++){
		cnt+=(v[i]/mid);
	}
		
	if(cnt<n){
		binarySearch(start, mid);
	} 
//	else if(cnt>n){
//		binarySearch(mid, End);
//	}
	else{
		anss.push_back(mid);
		binarySearch(mid+1, End);	
	}
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();
	
	binarySearch(s, e+1);

	sort(anss.begin(), anss.end());
	cout << *(anss.end()-1);
	
	return 0;
}
