#include <iostream>
#include <vector>
using namespace std;

int n, sx, sy, d, gener, ans; 
int dx[4]={1, 0, -1, 0}, dy[4]={0, -1, 0, 1};
bool map[101][101];

bool check(int x, int y){
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			if(!map[x+i][y+j]) return false;
		}
	}
	return true;
}

void run(int x, int y, vector<int> &dirs, int cnt){
	if(cnt==gener) return ;
	
	int dirs_size=dirs.size();
	for(int i=dirs_size-1; i>=0; i--){
		int ndir=(dirs[i]+3)%4;
		
		x+=dx[ndir];	y+=dy[ndir];
		map[x][y]=true;	
		
		dirs.push_back((ndir+2)%4);
	}
	
	run(x, y, dirs, cnt+1);
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	cin >> n;
	while(n--){
		cin >> sx >> sy >> d >> gener;
		
		map[sx][sy]=true;
		map[sx+dx[d]][sy+dy[d]]=true;
		vector<int> dirs={(d+2)%4};
		
		run(sx+dx[d], sy+dy[d], dirs, 0);
	}

	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			if(check(i, j))	ans++;
		}
	}
		
	cout << ans;
	return 0;
}
