#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> graph;
int total;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	while(getline(cin, s)){
		graph[s]++;
		total++;
	}
	
	cout << fixed;
	cout.precision(4);
	for(auto iter=graph.begin(); iter!=graph.end(); iter++){
		double ratio=(double)(iter->second)/(double)total*100;
		cout << iter->first << ' ' << ratio << '\n';
	}
	
	return 0;
}
