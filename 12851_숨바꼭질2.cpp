#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int n, k;
int visit[MAX];
int time, count;

void bfs(){
	queue<int> q;
	q.push(n);
	visit[n]=1;

	while(!q.empty()){
		int t=q.front();
		q.pop();
		
		if(visit[t]==time && count!=0) break;
		
		if(t+1<=100000 && visit[t+1]==0){
			if(t+1==k){
				time=visit[t]+1;
				count++;
				continue;
			}

			q.push(t+1);
			visit[t+1]=visit[t]+1;
		}		
		if(t-1>=0 && visit[t-1]==0){
			if(t-1==k){
				time=visit[t]+1;
				count++;
				continue;
			}

			q.push(t-1);
			visit[t-1]=visit[t]+1;
		}
		if(t*2<=100000 && visit[t*2]==0){
			if(t*2==k){
				time=visit[t]+1;
				count++;		
				continue;
			}

			q.push(t*2);
			visit[t*2]=visit[t]+1;
		}
	}
	
	return ;
}

int main(){
	cin >> n >> k;
		
	bfs();
	cout << time-1 << '\n' << count;
	
	return 0;
} 
