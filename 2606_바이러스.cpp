//#include <iostream>
//using namespace std;
//int N, pairs;
//int G[101][100]={0};
//int visited[101]={0};
//
//int bfs(){
//	int q[N];
//	int f=-1, r=-1;
//	
//	q[++r]=1;
//	visited[1]=1;
//	
//	while(f!=r){
//		int t=q[++f];
//		
//		for(int i=1; G[t][i]!=0; i++){
//			int nt=G[t][i];
//			if(!visited[nt]){
//				q[++r]=nt;
//				visited[nt]=1;
//			}
//		}
//	}
//	
//	return r;
//}
//
//int main(){
//	cin >> N >> pairs;
//	for(int i=0; i<pairs; i++){
//		int p1, p2;
//		cin >> p1 >> p2;
//		G[p1][++G[p1][0]]=p2;
//		G[p2][++G[p2][0]]=p1;
//	}	
//
//	cout << bfs();
//	return 0;
//} 

// dfs
#include <iostream>
#include <vector>
using namespace std;

int n, k, ans; 

vector<int> v[101];
bool visit[101];

void dfs(int x){
	visit[x]=true;
	ans++;
	
	int neight_size=v[x].size();
	for(int i=0; i<neight_size; i++){
		int nx=v[x][i];
		if(visit[nx]) continue;
		dfs(nx);
	}
	
	return ;
}

int main(){
	cin >> n >> k;
	for(int i=0; i<k; i++){
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	dfs(1);
	cout << ans-1;	
}
