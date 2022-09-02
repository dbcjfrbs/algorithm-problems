#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int n;

int main(){
	cin >> n;
	for(int i=1; i<=n; i++) q.push(i);
	
	int tmp;
	while(1){
		cout << q.front() << ' ';
		q.pop();
				
		if(q.empty()) break;
		
 		tmp=q.front();
		q.pop();
		q.push(tmp);		
	}	
	
	return 0;
}
