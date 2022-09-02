#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> p) {
    vector<vector<int> > v;

    int p_size=p.size();
    for(int i=0; i<p_size-1; i++){
        int min_idx=-1, min=p[i];
        for(int j=i+1; j<p_size; j++){
            if(min>p[j]){
                min=p[j];                
                min_idx=j;
            }
        }

        if(min_idx!=-1){
            int tmp=p[i];
            p[i]=p[min_idx];
            p[min_idx]=tmp;

            v.push_back({i, min_idx});
            v.push_back({min_idx, i});
        }
    }
    
    int v_size=v.size(); 
    vector<int> ans(p_size, 0);
    for(int i=0; i<v_size; i++){
        ans[v[i][0]]++;                
        // ans[v[i][1]]++;               
        // cout << ans[i] << ' ';
    }

    return ans;
}
