#include <string>
#include <vector>
#include <sstream>
using namespace std;

int plans_arr[300001][21];

int binarySearch(){



}

vector<int> solution(int n, vector<string> plans, vector<string> clients) {
    int c_size=clients.size(), p_size=plans.size();
    vector<int> answer;
    plans_arr[p_size+1][n];

    for(int i=0; i<p_size; i++){
        stringstream ss(clients[i]);
        int plan, tmp, idx=0;
        ss >> plans_arr[i][idx++];
        while(ss >> tmp) plans_arr[i][idx++]=tmp;
    }

    for(int i=0; i<c_size; i++){
        stringstream ss(clients[i]);
        int plan;
        vector<int> adds;
        
        ss >> plan;
        int tmp;
        while(ss >> tmp) adds.push_back(tmp);


    }


    return answer;
}
