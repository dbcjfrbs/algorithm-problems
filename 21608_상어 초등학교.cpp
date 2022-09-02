#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int n, map[20][20], ans;
int order[400], table[401][4];
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1, 0};

bool compare(vector<int> a, vector<int> b){
	if(a[0]>b[0]) return true;
	else if(a[0]==b[0]){
		if(a[1]>b[1]) return true;
		else if(a[1]==b[1]){
			if(a[2]<b[2]) return true;
			else if(a[2]==b[2]){
				if(a[3]<b[3]) return true;
			}
		}
	}
	
	return false;
}

void findSeat(int x){
	vector<vector<int> > v;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j]!=0) continue;
			
			int like=0, empty=0;
			for(int k=0; k<4; k++){
				int ni=i+dx[k], nj=j+dy[k];
			 	if(ni<0 || n<=ni || nj<0 || n<=nj) continue;
			 	
			 	if(map[ni][nj]==0) empty++;			 	
			 	else {
			 		for(int l=0; l<4; l++){
			 			if(map[ni][nj]==table[x][l]) like++;	
					}	
				}
			 	
			}
			
			v.push_back({like, empty, i, j});
		}
	}
	
	sort(v.begin(), v.end(), compare);
	map[v[0][2]][v[0][3]]=x;

	return ;
}

int main(){
	cin >> n;
	for(int i=0; i<n*n; i++){
		int t;
		cin >> t;
		order[i]=t;
		for(int j=0; j<4; j++) cin >> table[t][j];	
	}
// 자리 배정 
	for(int i=0; i<n*n; i++){
		findSeat(order[i]);
	}
// 만족도 계산 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int like=0;
			for(int k=0; k<4; k++){
				int ni=i+dx[k], nj=j+dy[k];
			 	if(ni<0 || n<=ni || nj<0 || n<=nj) continue;
				 
				int x=map[i][j];
			 	for(int l=0; l<4; l++){
			 		if(map[ni][nj]==table[x][l]) like++;	
				}
			}
			
			if(like==0) ans+=0;
			else ans+=pow(10, like-1);
		}
	}
	
	cout << ans;
	
	return 0;
}
