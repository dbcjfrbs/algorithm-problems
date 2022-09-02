#include <string>
#include <vector>
using namespace std;

int ans, map[10][20], n, rocks;
vector<vector<int> > seats, rockss;
int seats_size;

bool check(vector<int> seat, vector<vector<bool> > &visit2){
	int x=seat[0], y=seat[1];
// /체크 
	for(int i=0; i<n; i++){
		if(y%2==0){
			visit2[i][y]=true;
			visit2[i][y+1]=true;			
		}
		else{
			visit2[i][y-1]=true;
			visit2[i][y]=true;
		}
	}	
// \체크 
//	for(int i=n-1; i>=0; i--){
//		int N=i*2;
//		if(y%2==0){
//			if(N-y-1>=0){
//				visit2[i][N-y]=true;
//				visit2[i][N-y-1]=true;		
//			}
//		}
//		else{
//			if(N-y>=0){
//				visit2[i][N-y]=true;
//				visit2[i][N-y+1]=true;			
//			}
//		}
//	}	
// 다시 
	int ty=y+(n-1-x)*2;
	for(int i=n-1; i>=0; i--){
		if(y%2==0){
			if(ty>=0){
				if(ty==0){
					visit2[i][ty]=true;					
				}
				else{
					visit2[i][ty-1]=true;
					visit2[i][ty]=true;			
				}
			}
		}
		else{
			if(ty>=-1){
				if(ty==-1){
					visit2[i][ty+1]=true;					
				}
				else{
					visit2[i][ty+1]=true;
					visit2[i][ty]=true;			
				}
			}
		}
		
		ty-=2;
	}	


// -체크
	int N=n*2-1;
	for(int i=0; i<N; i++){
		visit2[x][i]=true;
	}
	
	int r_size=rockss.size();
	for(int i=0; i<r_size; i++){
		int rx=rockss[i][0], ry=rockss[i][1];
		if(visit2[rx][ry]) return false;
	}
	
	return true;
}

void dfs(int depth, int start, vector<vector<bool> > visit){
	if(depth==rocks){
		ans++;
		return ;
	}
	
	for(int i=start; i<seats_size-rocks+depth+1; i++){
		vector<vector<bool> > visit2(10, vector<bool>(20, false));
		for(int k=0; k<10; k++){
			for(int j=0; j<20; j++) visit2[k][j]=false;
		}
		if(!check(seats[i], visit2)) continue;
		
		vector<vector<bool> > visit3(10, vector<bool>(20, false));
		for(int k=0; k<10; k++){
			for(int j=0; j<20; j++){
				visit3[k][j]=(visit[k][j]||visit2[k][j]);
			}
		}
		
		rockss.push_back(seats[i]);		
		dfs(depth+1, i+1, visit3);	
		rockss.pop_back();
	}	
	
	return ;
}

int solution(int n_, int rocks_) {
	n=n_; rocks=rocks_;

	for(int i=0; i<n; i++){
		for(int j=0; j<i*2+1; j++){
			seats.push_back({i, j});
			seats_size++;
		}
	}
		
	vector<vector<bool> > visit(10, vector<bool>(20, false));
	dfs(0, 0, visit);

    return ans;
}
