#include <iostream>
#include <queue>
using namespace std;

int n, w, l;
int weight, ans; // �ٸ� �� Ʈ�� �߷� 
queue<int> q; 
vector<pair<int, int> > bridge;

int Go(){
// �ð� �߰��ϱ�
	int b_size=bridge.size();
	for(int i=0; i<b_size; i++){
		bridge[i].second++;
	}
// �ٸ��� �ǳʰ��� ����� 
	if(!bridge.empty() && bridge.begin()->second==w+1){
		weight-=bridge.begin()->first;	
		bridge.erase(bridge.begin());
	}
// Ʈ���� �߰��Ǹ� �����ϱ� 
	if(weight+q.front()<=l){
		weight+=q.front();
		bridge.push_back({q.front(), 1});
		q.pop();
	}
		
	return 1;
}

int main(){
	cin >> n >> w >> l;
	for(int i=0; i<n; i++){
		int t;
		cin >> t;
		q.push(t);
	}
	
	while(!q.empty()){
		ans+=Go();
	}	

	cout << ans+w;
	
	return 0;
}
