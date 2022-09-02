#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> a, vector<int> b){
	if(a[0]==b[0]) return a[3]>b[3];
	return a[0]<b[0];
}

int calc(vector<vector<int> > &v, int i){
	int power=v[i][3], dist=v[i][4], acc_time=v[i][1], acc_time_=0, ret=0; 

	do{
		acc_time_++;
		ret=1/2*power*acc_time_*acc_time_;
	}while(ret<distance);

	return ret;
}

void heapify(vector<vector<int> > &v, int size){
	int root=0, child=1;
	do{
		if(child+1<size && v[child][0]>v[child+1][0]) child++;
		if(v[root][0]>v[child][0]){
			vector<int> tmp=v[root][0];
			v[root][0]=v[child][0];
			v[child][0]=tmp;
		}
		else break;
		
		root=child;
		child=root*2+1;
	}while(child<size);
	
	return ;
}

int solution(int fuel, vector<int> powers, vector<int> distances) {
	vector<vector<int> > v;
	int size=powers.size();
	for(int i=1; i<=size; i++){
		int time=calc(v, i);
		v.push({time, 1, i, powers[i], distances[i]}); // 시간, 연료, 로켓번호, 파워, 거리 순 
	}
	
	sort(v.begin(), v.end(), compare);
	
	fuel-=size;
	while(fuel--){
		int time=calc(v, 0);
		v[0][0]=time;
		heapify(v, size);
	}

	cout << (*(v.end()-1))[0];
}
