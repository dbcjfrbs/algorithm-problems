#include <iostream>
#include <stack>
using namespace std;


int main(){
	int k;
	stack<int> s;
		
	cin >> k;

	int tmp;
	for(int i=0; i<k; i++){
		cin >> tmp;
		if(tmp==0) s.pop();
		else s.push(tmp);
	}
	
	int size=s.size(), ans=0;
	while(size--){
		tmp=s.top();
		s.pop();
		
		ans+=tmp;
	}
	
	cout << ans;

	return 0;
}
