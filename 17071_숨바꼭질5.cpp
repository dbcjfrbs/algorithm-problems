#include <iostream>
#include <string.h>
using namespace std;
int n, k;
int visit[2][500001];
int dp[1001];
int q[1000002];

//void bfs(){
//	int r=-1, f=-1;
//	q[++r]=n;
//	visit[0][n]=0;
//	
//	int t, cnt=0;
//	while(f!=r){
//		int size=r-f;
//		while(size--){
//			t=q[++f];	
//			
//			if(0<=t-1 && t-1<=500000 && (visit[0][t-1]==-1 || visit[1][t-1]==-1)){
//				if(visit[0][t]==cnt && visit[1][t-1]==-1){
//					q[++r]=t-1;
//					visit[1][t-1]=cnt+1;
//				}
//				if(visit[1][t]==cnt && visit[0][t-1]==-1){
//					q[++r]=t-1;
//				    visit[0][t-1]=cnt+1;
//				}
//			}
//			if(0<=t+1 && t+1<=500000 && (visit[0][t+1]==-1 || visit[1][t+1]==-1)){
//				if(visit[0][t]==cnt && visit[1][t+1]==-1){
//					q[++r]=t+1;
//					visit[1][t+1]=cnt+1;	
//				}
//				if(visit[1][t]==cnt && visit[0][t+1]==-1){
//					q[++r]=t+1;
//					visit[0][t+1]=cnt+1;	
//				}
//			}
//			if(0<=t*2 && t*2<=500000 && (visit[0][t*2]==-1 || visit[1][t*2]==-1)){
//				if(visit[0][t]==cnt && visit[1][t*2]==-1){
//					q[++r]=t*2;	
//					visit[1][t*2]=cnt+1;
//				} 
//				if(visit[1][t]==cnt && visit[0][t*2]==-1){
//					q[++r]=t*2;
//					visit[0][t*2]=cnt+1;
//				}
//			}
//		}
//		
//		cnt++;	
//	}
//	
//	return ;
//}
void bfs(){
	int r=-1, f=-1;
	q[++r]=n;
	visit[0][n]=0;
	
	int t;
	while(f!=r){
		t=q[++f];	
			
		if(0<=t-1 && t-1<=500000 && (visit[0][t-1]==-1 || visit[1][t-1]==-1)){
			if(visit[0][t]!=-1 && visit[1][t-1]==-1){
				q[++r]=t-1;
				visit[1][t-1]=visit[0][t]+1;
			}
			if(visit[1][t]!=-1 && visit[0][t-1]==-1){
				q[++r]=t-1;
			    visit[0][t-1]=visit[1][t]+1;
			}
		}
		if(0<=t+1 && t+1<=500000 && (visit[0][t+1]==-1 || visit[1][t+1]==-1)){
			if(visit[0][t]!=-1 && visit[1][t+1]==-1){
				q[++r]=t+1;
				visit[1][t+1]=visit[0][t]+1;	
			}
			if(visit[1][t]!=-1 && visit[0][t+1]==-1){
				q[++r]=t+1;
				visit[0][t+1]=visit[1][t]+1;	
			}
		}
		if(0<=t*2 && t*2<=500000 && (visit[0][t*2]==-1 || visit[1][t*2]==-1)){
			if(visit[0][t]!=-1 && visit[1][t*2]==-1){
				q[++r]=t*2;	
				visit[1][t*2]=visit[0][t]+1;
			} 
			if(visit[1][t]!=-1 && visit[0][t*2]==-1){
				q[++r]=t*2;
				visit[0][t*2]=visit[1][t]+1;
			}
		}			
	}
	
	return ;
}
int main(){
	cin >> n >> k;	

	int i=0;
	while(k<=500000){
		dp[i]=k;
		i++;
		k+=i;
	}

	memset(visit, -1, sizeof(visit));
	bfs();
	
	for(int x=0; x<i; x++){
		int t=dp[x];
		if(visit[0][t]!=-1 && visit[0][t]<=x && (x-visit[0][t])%2==0){
			cout << x;
			return 0;
		}
		if(visit[1][t]!=-1 && visit[1][t]<=x && (x-visit[1][t])%2==0){
			cout << x;
			return 0;
		}
	}
	cout << -1;

	return 0;
}
