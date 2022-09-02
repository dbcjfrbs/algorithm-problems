#include <iostream>
#include <string>
using namespace std;

int map[5][5], ans;
bool visit[1000000];
string arr[6];
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

void dfs(int x, int y, int cnt){
	if(cnt==6){
		string s;
		for(int i=0; i<6; i++) s+=arr[i];
		visit[stoi(s)]=true;
		
		return ;
	} 
	
	for(int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if(nx<0 || 5<=nx || ny<0 || 5<=ny) continue;
		arr[cnt]=to_string(map[nx][ny]);

		dfs(nx, ny, cnt+1);
	}
	
	return ;
}

int main(){
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++) cin >> map[i][j];
		
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++) dfs(i, j, 0);	
	
	for(int i=0; i<1000000; i++)
		if(visit[i]) ans++;	
	
	cout << ans;
	
	return 0;
}

