#include <iostream>
#include <string>
using namespace std;

int tc, count;
char map[3][4], simul[3][4];

void init(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++) simul[i][j]='.';
	}
	count=0;
	
	return ;
}

bool End(int x, int y){
	if(simul[0][0]!='.' && simul[0][0]==simul[1][1] && simul[1][1]==simul[2][2]) return true;
	if(simul[2][0]!='.' && simul[2][0]==simul[1][1] && simul[1][1]==simul[0][2]) return true;
	
	if(simul[x][y]!='.' && simul[x][y]==simul[x][0] && simul[x][y]==simul[x][1] && simul[x][y]==simul[x][2]) return true;
	if(simul[x][y]!='.' && simul[x][y]==simul[0][y] && simul[x][y]==simul[1][y] && simul[x][y]==simul[2][y]) return true;

	return false;
}

bool check(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(map[i][j]!=simul[i][j]) return false;
		}
	}
	
	return true; 
}

bool dfs(char who, int x, int y, int cnt){	
	if(cnt==count && check()){
		cout << "yes" << '\n';
		return true;
	}
	
	if(End(x, y)) return false;
				
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(simul[i][j]!='.' || map[i][j]=='.') continue;

			if(who=='X'){
				simul[i][j]='X';
				if(dfs('O', i, j, cnt+1)) return true;
				simul[i][j]='.';								
			}
			else{
				simul[i][j]='O';
				if(dfs('X', i, j, cnt+1)) return true;
				simul[i][j]='.';
			}
		}
	}
	
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> tc;
	while(tc--){
		init();
		cin >> map[0] >> map[1] >> map[2];
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(map[i][j]!='.') count++;
			}
		}
		
		if(tc!=0){
			cin.ignore();
			getchar();
		}
		
		bool tmp=dfs('X', 0, 0, 0);
		if(!tmp) cout << "no" << '\n';		
	}
	
	return 0;
} 
