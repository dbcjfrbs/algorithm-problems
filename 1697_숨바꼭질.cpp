#include <iostream>
using namespace std;
int n, k, cnt;
int visited[100001]={0}; 
int q[100001];
int f=-1, r=-1;

int isWall(int x){
	if(x<0 || x>100000) return 1;
	return 0;
}

int bfs(){
	q[++r]=n;
	visited[n]=1;
	
	int cnt=0;
	while(f!=r){
		int t=q[++f];
		int nt_arr[3]={t-1, t+1, t*2};
		
		for(int i=0; i<3; i++){
			int nt=nt_arr[i];
			if(nt==k) return visited[t];
			
			if(!isWall(nt)){
				if(!visited[nt]){
					q[++r]=nt;
					visited[nt]=visited[t]+1;
				}
			}
		}
	}
}

int main(){
	cin >> n >> k;


	if(n>=k) cout << n-k;
	else cout << bfs();
	
	return 0;
} 
