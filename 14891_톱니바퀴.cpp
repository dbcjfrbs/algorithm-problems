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
// ������ ��Ϲ����� ������ �� ��� ��ȯ 
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
// ������ ��Ϲ����� ���������� ���� �Ļ��Ǵ� �ֺ� ��Ϲ�������� ������ �� ��� ��ȯ 
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
// ��� ��Ϲ������� �� ����Ŭ���� ������ �� ���̿��ϴ� ��Ͽ��� �ֽ�ȭ 
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
