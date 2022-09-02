#include<iostream>
using namespace std;

int n, f, r, ans;

int main(int argc, char** argv)
{
	cin >> n;

	int arr[n]={0};
	bool check[n]={0};
	for(int i=0; i<n; i++) cin >> arr[i];

	while(r!=n){
		if(check[arr[r]]){
			check[arr[f++]]=false;
			continue;
		}

		// cout << f << ' ' << r << '\n';
		ans+=r-f+1;
		check[arr[r++]]=true;
	} 

	cout << ans;
	return 0;
}
