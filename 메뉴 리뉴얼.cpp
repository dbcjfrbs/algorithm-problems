#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

map<string, int> menu_cnt;

void comb(int depth, int start, int dishes_size, int cnt, string dishes, string dish){
    if(depth==cnt){
        menu_cnt[dish]++;
        return ;
    }
    
    for(int i=start; i<dishes_size-cnt+depth+1; i++){
        comb(depth+1, i+1, dishes_size, cnt, dishes, dish+dishes[i]);
    }
    
    return ;
}

void select(vector<string>& answer){
    int maxCnt=0;
    for(auto iter=menu_cnt.begin(); iter!=menu_cnt.end(); iter++){
        if((iter->second)>maxCnt) maxCnt=iter->second;
    }
    if(maxCnt<2) return ;
    
    for(auto iter=menu_cnt.begin(); iter!=menu_cnt.end(); iter++){
        if((iter->second)==maxCnt) answer.push_back(iter->first);
    }
    
    return ;    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    int c_size=course.size(), o_size=orders.size();
    
    for(int i=0; i<o_size; i++){
        sort(orders[i].begin(), orders[i].end());
    }

    for(int i=0; i<c_size; i++){
        for(int j=0; j<o_size; j++){        
            int oo_size=orders[j].size();
            if(course[i]>oo_size) continue;
            comb(0, 0, oo_size, course[i], orders[j], "");
        }
        
        select(answer);
        menu_cnt.clear();
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
