#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m, g, r, ans;
int map[50][50];
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

vector<int> loc;
vector<pair<int, int> > land;

void SWAP(int &a, int &b){
	int tmp=a; a=b; b=tmp; return ;
}

bool next_perm(){
	int n=loc.size();
	int i=n-1;
	while(i-1>=0 && loc[i-1]>=loc[i]) i--;
	if(i-1==-1) return false;
	
	int j=n-1;
	while(loc[i-1]>=loc[j]) j--;
	
	SWAP(loc[i-1], loc[j]);
	 
	while(i<n-1){
		SWAP(loc[i], loc[n-1]);
		i++; n--;
	}

	return true;
}

int solve(){
	pair<int, int> garden[50][50];
	queue<pair<int, int> > q;

	for(int i=0; i<land.size(); i++){
		if(loc[i]==0) continue;	
		
		garden[land[i].first][land[i].second]={0, loc[i]};	
		q.push({land[i].first, land[i].second});
	}
	
	int cnt=0;
	while(!q.empty()){
		int x=q.front().first, y=q.front().second, time=garden[x][y].first, val=garden[x][y].second;
		q.pop();
		
		if(val==3) continue;
		
		for(int i=0; i<4; i++){
			int nx=x+dx[i], ny=y+dy[i];
			if(nx<0 || n<=nx || ny<0 || m<=ny || map[nx][ny]==0) continue;
			
			int ntime=garden[nx][ny].first, nval=garden[nx][ny].second;
			if(nval!=0){
				if(nval==1 && val==2 && time+1==ntime){
					garden[nx][ny]={time+1, 3}; //²ÉÀÌ ÇË
					cnt++;
				}
				else if(nval==2 && val==1 && time+1==ntime){
					garden[nx][ny]={time+1, 3}; //²ÉÀÌ ÇË
					cnt++;
				}
				
				continue;
			}
			
			garden[nx][ny]={time+1, val};
			q.push({nx, ny});			
		}
	}

	return cnt;
}

void INPUT(){
	cin >> n >> m >> g >> r;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> map[i][j];
			if(map[i][j]==2){
				loc.push_back(0);
				land.push_back({i, j});	
			} 
		}
	}
	
	for(int tmp=r+g-1; tmp>=g; tmp--){
		loc[tmp]=2; // »¡°­ÀÌ¸é 2	
	}
	for(int tmp=g-1; tmp>=0; tmp--){
		loc[tmp]=1; // ³ì»öÀÌ¸é 1
	}
	sort(loc.begin(), loc.end());
	
	return ;
}

int main(){
	INPUT();
		
	do{
		int t=solve();
		if(ans<t) ans=t; 
	}while(next_perm());
	
	cout << ans;
	return 0;
}
