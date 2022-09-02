#include <string>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>
using namespace std;

int r, c;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
bool visit[50][50][50][50];

vector<string> p1={
	".F.FFFFF.F",
	".########.",
	".########F",
	"...######F",
	"##.######F",
	"...######F",
	".########F",
	".########.",
	".#...####F",
	"...#......"
};

int bfs(vector<string> &grid, int k, int x, int y){
    queue<vector<int> > q;
    vector<int> cnts;
    q.push({x, y, k, 0});
    visit[x][y][k][0]=true;

    while(!q.empty()){
        int q_size=q.size();
        for(int i=0; i<q_size; i++){
            int tx=q.front()[0], ty=q.front()[1], tp=q.front()[2], ts=q.front()[3];
            q.pop();

			if(ts>r+c) continue;		
            if(tx==r-1 && ty==c-1){
                cnts.push_back(ts);
                continue;
            }

            for(int j=0; j<4; j++){
                int nx=tx+dx[j], ny=ty+dy[j], np=tp-1;
//                if(nx<0 || nx>=r || ny<0 || ny>=c || np<0 || visit[nx][ny][np] || visit[nx][ny][k] || grid[nx][ny]=='#') continue;

                if(nx<0 || nx>=r || ny<0 || ny>=c || np<0 || grid[nx][ny]=='#') continue;
					
                if(grid[nx][ny]=='.'){
					if(visit[nx][ny][k][ts+1]) continue;
//                	if(visit[nx][ny][k]) continue;
                    q.push({nx, ny, k, ts+1});
                    visit[nx][ny][k][ts+1]=true;
                }

				if(visit[nx][ny][np][ts]) continue;
                q.push({nx, ny, np, ts});
                visit[nx][ny][np][ts]=true;
            }
        }
    }

    int ret=r+c, cnts_size=cnts.size();
    for(int i=0; i<cnts_size; i++){
        if(ret>cnts[i]) ret=cnts[i];
        cout << cnts[i] << ' ';
    }

    return ret;
}

int solution(vector<string> grid, int k){
    r=grid.size(); c=grid[0].size();
    int answer = bfs(grid, k, 0, 0);
    return answer;
}

int main(){
	cout << solution(p1, 6);
	return 0;
}
