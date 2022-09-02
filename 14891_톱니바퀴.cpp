#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset
#include <math.h> 
using namespace std;

int ans, cnt;
vector<vector<int> > process(100, vector<int>(2)), v(4, vector<int>(2));
vector<string> gears(5);

void init(){
	for(int i=1; i<=4; i++) cin >> gears[i];
	cin >> cnt;
	for(int i=0; i<cnt; i++) cin >> process[i][0] >> process[i][1];
	
	v[1]={gears[1][2], gears[2][6]};
	v[2]={gears[2][2], gears[3][6]};
	v[3]={gears[3][2], gears[4][6]};
	return ;
}
// 지정된 톱니바퀴의 움직인 후 모습 반환 
void rotate(int order, int dir){
	if(dir==1){
		string next=gears[order][7]+gears[order].substr(0, 7);
		gears[order]=next;	
	}
	else{
		string next=gears[order].substr(1, 7)+gears[order][0];
		gears[order]=next;
	}
		
	return ;
}
// 지정된 톱니바퀴의 움직임으로 인해 파생되는 주변 톱니바퀴들까지 움직인 후 모습 반환 
void effect(int order, int dir){
	int dirs[5]={0, 0, 0, 0, 0};
	dirs[order]=dir;
	for(int i=1; i<=3; i++){
		if(1<=order-i && v[order-i][0]!=v[order-i][1]){
			dirs[order-i] = (dirs[order-i+1]==1) ? -1 : 1;
			rotate(order-i, dirs[order-i]);
		}
		else break;
	}
	for(int i=1; i<=3; i++){
		if(order+i<=4 && v[order+i-1][0]!=v[order+i-1][1]){
			dirs[order+i] = (dirs[order+i-1]==1) ? -1 : 1;
			rotate(order+i, dirs[order+i]);
		}
		else break;
	}		

	return ;
}
// 모든 톱니바퀴들이 한 사이클동안 움직인 후 겹이웃하는 톱니영역 최신화 
void v_update(){
	v[1]={gears[1][2], gears[2][6]};
	v[2]={gears[2][2], gears[3][6]};
	v[3]={gears[3][2], gears[4][6]};

	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();
	for(int i=0; i<cnt; i++){
		rotate(process[i][0], process[i][1]);
		effect(process[i][0], process[i][1]);
		v_update();		
	}

	for(int i=1; i<=4; i++){
		if(gears[i][0]=='1') ans+=pow(2, i-1);		 
	}
	cout << ans;
		
	return 0;
}
