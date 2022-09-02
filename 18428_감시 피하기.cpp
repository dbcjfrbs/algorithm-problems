#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
char map[6][6];
vector<pair<int, int> > positions, teachers;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
string ans="NO";

void Input();
void Position();
void Comb(int depth, int start, int pos_size);
void Calc();

int main(){
	Input();
	Position();
	Comb(0, 0, positions.size());
	
	cout << ans;
	
	return 0;
}

void Input(){
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			cin >> map[i][j];
			if(map[i][j]=='T') teachers.push_back({i, j});				
		}
}

void Position(){
	bool visit[6][6]={false,};
	int t_size=teachers.size();
	for(int i=0; i<t_size; i++){
		int x=teachers[i].first, y=teachers[i].second;
		for(int j=0; j<n; j++){
			if(map[j][y]=='X' && !visit[j][y]){
				positions.push_back({j, y});
				visit[j][y]=true;	
			}
			if(map[x][j]=='X' && !visit[x][j]){
				positions.push_back({x, j});
				visit[x][j]=true;	
			} 
		}
	}
}

void Comb(int depth, int start, int pos_size){
	if(depth==3){
		Calc();
		return ;		
	}
	
	for(int i=start; i<pos_size-2+depth; i++){
		int x=positions[i].first, y=positions[i].second;
		map[x][y]='O';
		Comb(depth+1, i+1, pos_size);
		map[x][y]='X';
	}
}

void Calc(){
	int t_size=teachers.size(), cnt=0;
	for(int i=0; i<t_size; i++){
		int x=teachers[i].first, y=teachers[i].second;
		for(int j=0; j<4; j++){
			int nx=x+dx[j], ny=y+dy[j];
			
			while(1){
				if(nx<0 || n<=nx || ny<0 || n<=ny || map[nx][ny]=='T' || map[nx][ny]=='O') break;
				else if(map[nx][ny]=='S') cnt++;
				nx+=dx[j];	ny+=dy[j];
			}
		}	
	}	
	if(cnt==0) ans="YES";
	
	return ;
}
