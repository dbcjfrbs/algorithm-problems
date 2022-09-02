#include<iostream>
#include<string>
using namespace std;

int r, c, n;
int map[500][500];
int loc_x, loc_y;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

void loc_update(){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(map[i][j]==0){
				loc_x=i;
				loc_y=j;
				return ;
			}
		}
	}
}

void map_update(int x, int y, int h, int w, int val){
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			map[x+i][y+j]=val;
		}
	}
	loc_update();
	return ;
}

void init(){
	cin >> r >> c >> n;
	for(int i=0; i<n; i++){
		int h, w;
		cin >> h >> w;
		map_update(loc_x,loc_y , h, w, i+1);
	}
}

void draw(){
	int R=2*r+1, C=2*c+1;
	char map_draw[R][C]={0, };

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(i%2==0 && j%2==0) map_draw[i][j]='+';				
			else if(i%2==0 && j%2==1) map_draw[i][j]='-';
			else if(i%2==1 && j%2==0) map_draw[i][j]='|';
			else map_draw[i][j]='.';

			if((i%2==0 && j%2==1) || (i%2==1 && j%2==0)){
				if(i==0 || i==R-1 || j==0 || j==C-1) continue;

				int x=i/2, y=(j-1)/2;
				for(int k=0; k<4; k++){
					int nx=x+dx[k], ny=y+dy[k];
					if(nx<0 || r<=nx || ny<0 || c<=ny) continue;
					// if(map[nx][ny]==map[x][y]) map_draw[i+dx[k]][j+dy[k]]='.';					
					if(map[nx][ny]==map[x][y]){
						map_draw[2*x+1+dx[k]][2*y+1+dy[k]]='.';
					}					
				}
			}

		}
	}


//	for(int i=0; i<R; i++){
//		for(int j=0; j<C; j++){
//			int cnt=0;
//			for(int k=0; k<4; k++){
//				int nx=i+dx[k], ny=j+dy[k];
//				if(nx<0 || R<=nx || ny<0 || C<=ny) continue;
//				if(map_draw[nx][ny]=='.') cnt++;
//			}
//			if(cnt==4) map_draw[i][j]='.';
//		}
//	}

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cout << map_draw[i][j];
		}
		cout << '\n';
	}
	return ;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init(); // map 업데이트까지 완료
	draw();

	return 0;
}
