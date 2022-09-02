#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> G[32001]; // 벡터 초기화 알아보기 
int input[32001];

void solve(){
	queue<int> q;
	for(int i=1; i<=n; i++){
		if(input[i]==0){
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int t=q.front();
		q.pop();
		cout << t << ' ';

		int nt_size=G[t].size();
		for(int i=0; i<nt_size; i++){
			int nt=G[t][i];
			if((--input[nt])==0) q.push(nt);
		}
	}
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int a, b;
	for(int i=0; i<m; i++){
		cin >> a >> b;
		G[a].push_back(b);
		input[b]++;
	}

	solve();
	
	return 0;
}
