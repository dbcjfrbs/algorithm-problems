#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#define MAX 101
using namespace std;
int tc, h, w;
char map[MAX][MAX];
int visit[MAX][MAX];
int hasKey[26];
//bfs 함수에 사용하는 변수
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
int ans;

void input(){
	cin >> h >> w;
	for(int i=0; i<h; i++){
		cin >> map[i];
	}

	char keys[27]={'\0'}; // 이거 떄문에 틀리는 이유는? 
	cin >> keys;
	if(keys[0]=='0'){
		return ;
	}
	for(int i=0;keys[i]!='\0'; i++){
		hasKey[keys[i]-'a']=1;
	}

//	for(int i=0;i<26; i++){
//		cout << hasKey[i];
//	}
	return ;
}

void bfs(int x, int y){
	if('A'<=map[x][y] && map[x][y]<='Z'){
		if(hasKey[map[x][y]-'A']!=1) return ;		
	}
	if('a'<=map[x][y] && map[x][y]<='z'){
		if(hasKey[map[x][y]-'a']!=1){
			memset(visit, 0, sizeof(visit));
		}
		
		hasKey[map[x][y]-'a']=1;
	}	
	if(map[x][y]=='$'){
		ans++;
		map[x][y]='.';
	}
	
	queue<pair<int, int> > q;
	q.push({x, y});
	visit[x][y]=1;
	
	pair<int, int> t;
	while(!q.empty()){
		t=q.front();
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx=t.first+dx[i], ny=t.second+dy[i]; 
			if(0<=nx && nx<h && 0<=ny && ny<w && visit[nx][ny]==0 && map[nx][ny]!='*'){
				if('A'<=map[nx][ny] && map[nx][ny]<='Z'){
					if(hasKey[map[nx][ny]-'A']!=1) continue;
				}
				if('a'<=map[nx][ny] && map[nx][ny]<='z'){
					if(hasKey[map[nx][ny]-'a']!=1){
						memset(visit, 0, sizeof(visit));
						while(!q.empty()){
							q.pop();	
						}
					}
					
					hasKey[map[nx][ny]-'a']=1;
				}
				if(map[nx][ny]=='$'){
					ans++;
					map[nx][ny]='.';
				}
								
				q.push({nx, ny});
				visit[nx][ny]=1;
			}
		}
	}
	
	return ;
}

void init(){
	ans=0;
	memset(visit, 0, sizeof(visit));
	memset(hasKey, 0, sizeof(hasKey));

	return;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> tc;
	while(tc--){
		init();
		input();

		vector<pair<int, int> > start; // 시작하는 위치 저장 
		for(int i=0; i<w; i++){
			if(map[0][i]!='*') start.push_back({0, i});
			if(map[h-1][i]!='*') start.push_back({h-1, i});
		}
		for(int i=1; i<h-1; i++){
			if(map[i][0]!='*') start.push_back({i, 0});
			if(map[i][w-1]!='*') start.push_back({i, w-1});
		}
		
//		for(int i=0; i<h; i++){
//			for(int j=0; j<w; j++){
//				cout << map[i][j];
//			}
//			cout << endl;
//		}
		
		int size=start.size();
		for(int i=0; i<26; i++){
			for(int j=0; j<size; j++){
				bfs(start[j].first, start[j].second);	
			}

			memset(visit, 0, sizeof(visit));
		}
		
		cout << ans << endl;
	}
		
	return 0;
}
