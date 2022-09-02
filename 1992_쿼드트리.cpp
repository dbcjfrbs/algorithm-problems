#include <iostream>
#define MAX 64
using namespace std;

int N, idx;
char map[MAX][MAX], comp[100000];
int dx[4]={0, 0, 1, 1}, dy[4]={0, 1, 0, 1}; // 각 트리 왼쪽 위 시작 꼭지점

void qaudTree(int n, int x, int y);
void tree(int n, int dir, int x, int y); 

void tree(int n, int dir, int x, int y){
	bool a=false, b=false;
	for(int i=x; i<x+n; i++){
		for(int j=y; j<y+n; j++){
			if(map[i][j]=='0'){
				a=true;
			}
			else{
				b=true;
			}
			
			if(a && b) {
				qaudTree(n, x, y);
				return ;
			}
		}
	}
	
	if(a) comp[idx++]='0';
	else comp[idx++]='1';

	return ;
}

void qaudTree(int n, int x, int y){
	comp[idx++]='(';
	
	for(int i=0; i<4; i++){
		tree(n/2, i, x+dx[i]*n/2, y+dy[i]*n/2);
	}

	comp[idx++]=')';

	return ;
}

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> map[i];
	}
	
	tree(N, 0, 0, 0);
		
	cout << comp;

	return 0;
}
