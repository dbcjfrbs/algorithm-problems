#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int idx, vector<string> goods, vector<string> &answer){
	string ptr, ans;
	vector<string> ptrs;
	
	int good_len=goods[idx].size();
	for(int i=1; i<=good_len; i++){
		for(int j=0; j<=good_len-i; j++){
			ptr=goods[idx].substr(j, i);
			
			int goods_size=goods.size();
			bool flag=false;
			for(int i=0; i<goods_size; i++){
				if(i==idx) continue;
				if(goods[i].find(ptr)!=string::npos) flag=true;
				if(flag) break; 
			}
	
// 고유 검색어를 찾았다면 
			if(!flag){
				ans=ptr;	
				ptrs.push_back(ans);
			}
		}
		
		if(!ptrs.empty()){
			sort(ptrs.begin(), ptrs.end());
			ptrs.erase(unique(ptrs.begin(), ptrs.end()), ptrs.end());
			
			string t;
			int ptrs_size=ptrs.size();
			for(int i=0; i<ptrs_size; i++){
				t+=ptrs[i];
				if(i!=ptrs_size-1) t+=" ";
			}
			
			answer.push_back(t);
			break;
		}
	}
	
	if(ptrs.empty()) answer.push_back("None");
	return ;
}

vector<string> solution(vector<string> goods) {
    vector<string> answer;
    
    int goods_size=goods.size();
	for(int i=0; i<goods_size; i++){
		solve(i, goods, answer);
	}    
    
    return answer;
}
