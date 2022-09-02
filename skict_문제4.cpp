#include <string>
#include <vector>
using namespace std;

int visit[300001];
vector<vector<int> > G(300001);

void dfs1(int x){
    visit[x]=1;
    if(x==)

    int size=G[x].size();
    for(int i=0; i<size; i++){
        if(visit==1) continue;
        dfs1(G[x][i]);
    }
}

long long solution(int n, vector<vector<int>> edges) {
    long long answer = 0;
    int size=edges.size();
    for(int i=0; i<size; i++){
        int from=edges[i][0], to=edges[i][1];
        G[from].push_back(to);
        G[to].push_back(from);
    }
    
    for(int i=0; i<n-1; i++){
        dfs(i);
    }

    return answer;
}
