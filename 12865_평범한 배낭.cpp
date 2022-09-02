#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<vector<int> > v(100);
int d[100001];

void Input();
void Solve();


int main(){
	Input();
	Solve();
	
	cout << d[k];
	
	return 0;
}

void Input(){
	cin >> n >> k;
	int w, val;
	for(int i=0; i<n; i++){
		cin >> w >> val;
		
//		v.push_back({w, val});
		v[i].push_back(w);
		v[i].push_back(val);
	}
	
}

void Solve(){
	for(int i=1; i<=k; i++){
		for(int j=0; j<n; j++){
			int w=v[j][0], val=v[j][1];
			
			if(i-w>=0 && d[i]<d[i-w]+val) d[i]=d[i-w]+val;
		}
		
		if(d[i]<d[i-1]) d[i]=d[i-1]; 
	}

	return ;
}
