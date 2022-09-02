#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;
map<string, int> visit;
string target="123456780";
// map에서 동서남북 방향을 문자열에 적용
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1}; 
int map[3][3]={1, 2, 3, 4, 5, 6, 7, 8, 0};

string swap(string x, int idx, int n_idx){
	char tmp;
	
	tmp=x[idx];
	x[idx]=x[n_idx];
	x[n_idx]=tmp;
	
	return x;
}

void bfs(string x){
	 queue<string> q;
	 q.push(x);
	 visit[x]=0;
	 
	 string t;
	 while(!q.empty()){
	 	t=q.front();
	 	q.pop();
	 	
	 	if(t==target){
	 		cout << visit[target];
	 		return ;
		 }
//	 	cout << 1;
	 	string nx;
	 	int idx, n_idx;
	 	for(int i=0; i<4; i++){
	 		idx=t.find('0');
	 		int x=idx/3, y=idx%3;
	 		int nx=x+dx[i], ny=y+dy[i];
	 		
			string nt;
			if(0<=nx && nx<3 && 0<=ny && ny<3){
		 		n_idx=nx*3+ny;
		 		nt=swap(t, idx, n_idx);
				if(visit.find(nt)!=visit.end()) continue;
				
				q.push(nt);
				visit[nt]=visit[t]+1;
			}	
		 }
	
	}
	cout << -1;
	
	return ;
}

int main(){
	string s, t;
	for(int i=0; i<9; i++){
		cin >> t;
		s+=t; // 시간복잡도 알아보기 
	}
	
	bfs(s);
	
	return 0;
}
