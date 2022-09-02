#include <iostream>
using namespace std;
int n, seq[100000], visit[2000000], x;
int ans;

int main(){
	scanf("%d", &n);
	int* p=seq; 
	for(int i=0; i<n; i++){
		scanf("%d", p++);
		visit[seq[i]]=1;
	}
	scanf("%d", &x);
	
	int t;
	for(int i=0; i<n; i++){
		if(x>seq[i]){
			t=x-seq[i];
			if(visit[t]==1 && t!=seq[i]){
				ans++;				
				visit[seq[i]]=0;
			}
		}
	}
	
	cout << ans;
	return 0;
}
