#include <iostream>
#include <string>

using namespace std;

int tc;
string cmds;
int x_min, x_max, y_min, y_max, x, y;
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1, 0};

void init(){
	x_min=0; x_max=0; y_min=0; y_max=0, x=0, y=0;
	return ;
}

void Calc(){
	int dir=0, cmds_len=cmds.size();
	for(int i=0; i<cmds_len; i++){
		if(cmds[i]=='F'){
			x+=dx[dir]; y+=dy[dir];	
		}
		else if(cmds[i]=='B'){
			x-=dx[dir]; y-=dy[dir];	
		}
		else if(cmds[i]=='L'){
			dir+=4;
			dir--;
			dir%=4;
		}
		else{
			dir++;
			dir%=4;
		}
		
		if(x<x_min) x_min=x; 
		if(x>x_max) x_max=x; 
		if(y<y_min) y_min=y; 
		if(y>y_max) y_max=y;
	}
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	
	cin >> tc;
	while(tc--){
		init();
		cin >> cmds;
		
		Calc();
		
		cout << (x_max-x_min)*(y_max-y_min) << '\n';
	}	
	
	return 0;
}
