#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <set>
using namespace std;

set<vector<bool> > anss;
vector<bool> visit(8, false);

bool compare(int b_size, vector<string>& selected, vector<string>& banned_id){
    for(int i=0; i<b_size; i++){
        regex re(banned_id[i]);
        if(!regex_match(selected[i], re)) return false;
    }
    return true;
}

void perm(int depth, int u_size, int b_size, vector<string>& selected, vector<string>& user_id, vector<string>& banned_id){
    if(depth==b_size){
        if(compare(b_size, selected, banned_id)){
            anss.insert(visit);
        }
        
        return ;
    }
    
    for(int i=0; i<u_size; i++){
        if(!visit[i]){
            visit[i]=true;
            
            selected.push_back(user_id[i]);
            perm(depth+1, u_size, b_size, selected, user_id, banned_id);
            selected.pop_back();
            
            visit[i]=false;        
        }
    }
    
    return ;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int b_size=banned_id.size(), u_size=user_id.size();
    for(int i=0; i<b_size; i++){
            
        for(int j=0; j<banned_id[i].size(); j++){
            if(banned_id[i][j]=='*') banned_id[i][j]='.';
        }
        banned_id[i]="^"+banned_id[i]+"$";
    }
    
    vector<string> selected;
    perm(0, u_size, b_size, selected, user_id, banned_id);  
    
    return anss.size();
}
