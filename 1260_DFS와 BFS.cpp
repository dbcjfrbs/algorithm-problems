#include <iostream>
using namespace std;
int n, m, v;
int G[1001][1001]={0}, visit[1001]={0};

void dfs(int v){
	int s[10000];
	int top=0;
	
	s[top]=v;
	while(top!=-1){
		if(visit[s[top]]){
			top--;
			continue;
		}
		
		int t=s[top--];
		visit[t]=1;
		cout << t << " ";
		
		for(int i=1000; i>=1; i--){
			if(G[t][i] && !visit[i]){
				s[++top]=i;
			}
		}
	}
	cout << endl;
	return ;
}

void bfs(int v){
	int q[1001];
	int f=-1, r=-1;
	
	q[++r]=v;
	visit[v]=1;
	while(f!=r){
		int t=q[++f];
		cout << t << " ";
		
		for(int i=1; i<1001; i++){
			if(G[t][i]==1 && visit[i]==0){
				q[++r]=i;
				visit[i]=1;
			}
		}
	}
	cout << endl;
	return ;
}

int main(){
	cin >> n >> m >> v;
	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		G[x][0]++;
		G[y][0]++;
		G[x][y]=1;
		G[y][x]=1;		
	}

	dfs(v);
	for(int i=1; i<=1001; i++){
		visit[i]=0;
	}
	bfs(v);
	
	return 0;
}
