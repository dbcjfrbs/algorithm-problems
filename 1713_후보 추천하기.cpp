#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, cnt, seq[1000];
vector<vector<int> > a(20, vector<int>(3, 0));

void Init(){
	cin >> n >> cnt;
	for(int i=0; i<cnt; i++) cin >> seq[i];
	
	return ;
}

void Substitute(int x){
	int minCnt=1001, maxTime=0, idx=0;
	for(int i=0; i<n; i++){
		if(minCnt>=a[i][1]){
			if(minCnt==a[i][1] && maxTime<a[i][2]){
				maxTime=a[i][2];
				idx=i;
			}
			else if(minCnt>a[i][1]){
				minCnt=a[i][1];
				maxTime=a[i][2];
				idx=i;	
			}
		}
	}

	a[idx][0]=seq[x];
	a[idx][1]=1;
	a[idx][2]=1;
	
	return ;
}

void Add(int idx){
	for(int i=0; i<n; i++) if(a[i][0]!=0) a[i][2]++; // 시간 늘리기 
	for(int i=0; i<n; i++){ // 사진틀에 있다면 추천수 늘리기 
		if(a[i][0]==seq[idx]){
			a[i][1]++;
			return ;
		}
	}
	// 사진틀에 없다면 
	for(int i=0; i<n; i++){
		if(a[i][0]!=0) continue; 

		a[i][0]=seq[idx];
		a[i][1]=1;
		a[i][2]=1;

		return ;
	}
	// 모두 꽉 찼다면
	Substitute(idx);
	
	return ;
}

int main(){
	Init();
	for(int i=0; i<cnt; i++) Add(i);		
	
	sort(a.begin(), a.end());
	for(int i=0; i<20; i++) if(a[i][0]!=0) cout << a[i][0] << ' ';		
	
	return 0;
}
