#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int T, n;
int visit[300][300];
pair<int, int > s, e;
int dx[8]={2, 1, -1, -2, -2, -1, 1, 2}, dy[8]={1,2 , 2 ,1, -1, -2, -2, -1};

int bfs(){
    queue<pair<int, int> > q;
    q.push(s);

    pair< int, int> t;
    while(!q.empty()){
        t=q.front();
        q.pop();
        if(t.first==e.first && t.second==e.second) return visit[e.first][e.second];

        for(int i=0; i<8; i++){
            int nx=t.first+dx[i], ny=t.second+dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<n && !visit[nx][ny]){
                q.push({nx, ny});
                visit[nx][ny]=visit[t.first][t.second]+1;
            }
        }
    }
}

int main(){
	cin >> T;	
	while(T--){
	    cin >> n;
	    cin >> s.first >> s.second;
	    cin >> e.first >> e.second;

	    memset(visit, 0, sizeof(visit));
	    cout << bfs() << endl;
	}

	return 0;
}
