#include <iostream>
#include <vector>
#define INF 100000001
#define MAX 1001
using namespace std;

int n, m, start, End;
vector<vector<int> > G[MAX];
int d[MAX];
bool visit[MAX];

void Input();

void Solve(int x);
int getSmall();

int main(){
	Input();
	
	d[start]=0;
	Solve(start);

	cout << d[End];
		
	return 0;
}

void Input(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int s, e, val;
		cin >> s >> e >> val;
		G[s].push_back({e, val});
	}	
	cin >> start >> End;

	for(int i=1; i<=n; i++) d[i]=INF;
	
	return ;
}

void Solve(int x){
	while(x!=End){
		visit[x]=true;

		int size=G[x].size();
		for(int i=0; i<size; i++){
			int node=G[x][i][0], add=G[x][i][1];
			if(d[node]>d[x]+add) d[node]=d[x]+add;						
		}	
		
		x=getSmall();
	}
	
	return ;
}

int getSmall(){ 
	int val=INF, idx;
	for(int i=1; i<=n; i++){
		if(visit[i]) continue;
		if(d[i]<val){
			val=d[i];
			idx=i;
		}
	}
	
	return idx;
}
