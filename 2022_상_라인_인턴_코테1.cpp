#include <string>
#include <vector>
#include <map>
#include <set> 
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> logs) {
    vector<string> answer;
    map<string, string> user_problem;
    map<string, int> problem;
    map<string, bool> user;
    int users=0;
    
    int logs_size=logs.size();
    for(int i=0; i<logs_size; i++){
        stringstream ss(logs[i]);
        string s1, s2, s3;
        ss >> s1 >> s2;
        s3=s1+s2;

        if(user_problem.find(s3)!=user_problem.end()) continue; // 같은 사람이, 같은 문제를 풀었을 때

        user_problem[s3]=s2;
        problem[s2]++;
        
        if(user.find(s1)!=user.end()) continue;  // 이미 문제를 하나라도 푼 사람일  
        user[s1]=true;
        users++;
    }
    
    int mid = users%2==0 ? users/2 : users/2+1;
    for(auto iter=problem.begin(); iter!=problem.end(); iter++){
        if((iter->second)>=mid) answer.push_back(iter->first); 
    }
    sort(answer.begin(), answer.end());
    return answer;
}

vector<string> solution2(vector<string> logs) {
    vector<string> answer;
    map<string, set<string> > user_problem;
    map<string, int> problem;
    
    int logs_size=logs.size();
    for(int i=0; i<logs_size; i++){
        stringstream ss(logs[i]);
        string s1, s2;
        ss >> s1 >> s2;

        if(user_problem[s1].find(s2)==user_problem[s1].end()){
	        user_problem[s1].insert(s2);
        	problem[s2]++;	
		}
    }
    
	int users=user_problem.size();		            
    int mid = users%2==0 ? users/2 : users/2+1;
    for(auto iter=problem.begin(); iter!=problem.end(); iter++){
        if((iter->second)>=mid) answer.push_back(iter->first); 
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main(){
	vector<string> v={"morgan sort", "felix reverse", "rohan sqrt", "felix sort", "flelix sort", "morgan sort", "asd asdasdasd", "asda asdasdasd"};
	
	vector<string> ans1=solution(v), ans2=solution2(v);
	for(string str : ans1) cout << str << ' ';
	cout << '\n';
	for(string str : ans2) cout << str << ' ';
	
	return 0;	
}
