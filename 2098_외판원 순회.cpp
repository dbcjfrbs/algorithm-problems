#include <iostream>
#define MAX 16000001;
using namespace std;
int n;
int arr[16][16];
int d[1<<16][16];

int tsp(int visit, int now){
	visit|=(1<<now);

	if(visit==(1<<n)-1){
		if(arr[now][0]>0){ // !안되는 이유는?
			return d[visit][now]=arr[now][0];
		}

		return d[visit][now]=MAX;
	}
	
	int &ret=d[visit][now];
	if(ret>0) return ret; // !ret 안되는 이유는? 
	ret=MAX;

	for(int i=0; i<n; i++){
		if((visit&(1<<i))==0 && arr[now][i]>0){ // & 와 && 중 우선순위는? 
			int val=tsp(visit, i)+arr[now][i];
			if(ret>val) ret=val;
		}
	}
	
	return ret;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}

	cout << tsp(0, 0);
	
	return 0;
}
