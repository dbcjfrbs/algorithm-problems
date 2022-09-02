#include <iostream>
using namespace std;

long long n, m, k;
long long arr[1000001]={0}, add[2][10000]={0}, visit[1000001]={0};
int main(){
	cin >> n >> m >> k;	long long acc=0;
	for(int i=1; i<=n; i++){
		long long t; cin >> t;
		acc+=t;
		arr[i]=acc; // ДЉРћЧе
	}

	int cnt=0;
	for(int i=0; i<m+k; i++){
		int t; cin >> t;
		if(t==1){
			long long idx, val; cin >> idx >> val;
			if(!visit[idx]){
				add[0][cnt]=idx;
				add[1][cnt++]=val;
				visit[idx]=1;
			}
			else{
				for(int j=0; add[0][j]!=0; j++){
					if(add[0][j]==idx){
						add[1][j]=val;
						break;
					}
				}
			}
		}
		else{
			long long s, e, sum; cin >> s >> e;
			sum=arr[e]-arr[s-1];
			for(int j=0; add[0][j]!=0; j++){
				long long idx=add[0][j];
				if(s<=idx && idx<=e){
					sum=sum-(arr[idx]-arr[idx-1])+add[1][j];
				}
			}

			cout << sum << endl;
		}
	}	

	return 0;
}
