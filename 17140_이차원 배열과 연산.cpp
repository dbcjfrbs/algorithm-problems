#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <map> 
using namespace std;

int r, c, k, arr[100][100];
int r_max=3, c_max=3, time=0;

void init(){
	cin >> r >> c >> k;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++) cin >> arr[i][j];
	}	
	return ;
}

bool compare(pair<int, int> a, pair<int, int> b){
	if(a.first==b.first) return a.second<b.second;
	return a.first<b.first;
}

void update(){	
	if(r_max>=c_max){
		for(int i=0; i<r_max; i++){
			map<int, int> num_cnt;
			vector<pair<int, int> > v;

			int j=0;
			while(j<c_max){
				if(arr[i][j]==0){
					j++;
					continue;
				}
				int num=arr[i][j++];
				num_cnt[num]++;
			}
			
			for(auto iter=num_cnt.begin(); iter!=num_cnt.end(); iter++){
				v.push_back({iter->second, iter->first});
			}
			
			sort(v.begin(), v.end(), compare);
			memset(arr[i], 0, sizeof(arr[i]));
			
			int idx=0;
			for(auto iter=v.begin(); iter!=v.end(); iter++){
				if(idx>=100) break;
				arr[i][idx++]=iter->second;
				arr[i][idx++]=iter->first;
			}
			
			c_max=max(c_max, idx);
			if(c_max>100) c_max=100;
		}
		
	}
	else{
		for(int j=0; j<c_max; j++){
			map<int, int> num_cnt;
			vector<pair<int, int> > v;

			int i=0;
			while(i<r_max){ // 문제지점 
				if(arr[i][j]==0){
					i++;
					continue;
				}
				int num=arr[i++][j];
				num_cnt[num]++;
			}
			
			for(auto iter=num_cnt.begin(); iter!=num_cnt.end(); iter++){
				v.push_back({iter->second, iter->first});
			}

			sort(v.begin(), v.end(), compare);	
			for(int x=0; x<r_max; x++) arr[x][j]=0;
			
			int idx=0;
			for(auto iter=v.begin(); iter!=v.end(); iter++){
				if(idx>=100) break;
				arr[idx++][j]=iter->second;
				arr[idx++][j]=iter->first;
			}
			
			r_max=max(r_max, idx);
			if(r_max>100) r_max=100;			
		}	
	}
	
	return ;
}

void run(){
	while(1){
		if(arr[r-1][c-1]==k || time>100) break;
		
		update();				
		time++;				
	}
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();
	run();
	
	if(time>100) cout << -1;
	else cout << time;

	return 0;
}
