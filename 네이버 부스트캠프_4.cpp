#include <string>
#include <vector>
#include <iostream>
using namespace std;

int max_weight, max_cnt, len;

void init(){
	max_weight=0;
	max_cnt=0;
	len=0;
	return ;
}

void comb(int depth, int start, int cnt, int sum, vector<int> a, vector<int>& weight){
	if(depth==cnt){
		int size=a.size();
		for(int i=0; i<size; i++){
			if(a[i]==sum/2 && a[i]>=max_weight){
				max_weight=a[i];
				max_cnt=cnt;
			}
		}
		
		return ;
	}
	
	for(int i=start; i<len-cnt+depth+1; i++){
		a.push_back(sum+weight[i]);
		comb(depth+1, i+1, cnt, sum+weight[i], a, weight);
		a.pop_back();
	}	

	return ;
}

void solution(vector<int> weight){
	vector<int> answer;
	len=weight.size();
	
	vector<int> a; 
	for(int i=1; i<len; i++){
		comb(0, 0, i+1, 0, a, weight);
	}	
	/
	answer.push_back(max_cnt);	
	answer.push_back(max_weight);		
	
	for(int i=0; i<2; i++){
		cout << answer[i] << ' ';
	}
	cout << '\n';
	
	return ;
} 

int main(){
	vector<int> t1={90, 90, 100, 40, 50, 45, 45};
	vector<int> t2={40, 90, 100, 80, 45, 35, 60};
	solution(t1);
	init();
	solution(t2);
	
}
