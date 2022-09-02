#include <iostream>
#define MAX 1000
using namespace std;

int h, w, x, y;
int map[MAX][MAX];

int main(){
	ios::sync_with_stdio(false);sil
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> h >> w >> x >> y;
	for(int i=0; i<h+x; i++){
		for(int j=0; j<w+y; j++){
			cin >> map[i][j];
		}
	}
	
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(i>=x && j>=y){
				map[i][j]-=map[i-x][j-y];
			}
			cout << map[i][j] << ' ';
		}
		
		cout << endl;
	}
	
	return 0;
}
