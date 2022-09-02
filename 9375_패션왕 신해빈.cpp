// 기존에 짜서 시간초과 난 코 
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int tc, n, ans;

void calc(){
	
}

void comb(int depth, int start, int cnt, int sum, vector<int> &kind_cnt, int kinds){
	if(depth==cnt){
		ans+=sum;
		return ;
	}
	
	for(int i=start; i<kinds-cnt+depth+1; i++){
		comb(depth+1, i+1, cnt, sum*kind_cnt[i], kind_cnt, kinds);
	}
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	
	cin >> tc;
	while(tc--){
		map<string, int> kind_is;
		int kinds=0;
		string item, kind;
		
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> item >> kind;
			
			if(kind_is.find(kind)==kind_is.end()) kinds++;
			kind_is[kind]++;			
		}
				
		vector<int> kind_cnt;
		for(auto iter=kind_is.begin(); iter!=kind_is.end(); iter++){
			kind_cnt.push_back(iter->second);
		}
			
		ans=0;
		for(int i=1; i<=kinds; i++){
			comb(0, 0, i, 1, kind_cnt, kinds);
		}
		
		cout << ans << '\n';
	}
		
	return 0;
}




// 다시 짠 코 
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int tc, n, ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	드 
	
	cin >> tc;
	while(tc--){
		map<string, int> kind_is;
		int kinds=0;
		string item, kind;
		
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> item >> kind;
			
			if(kind_is.find(kind)==kind_is.end()) kinds++;
			kind_is[kind]++;
		}

		vector<int> kind_cnt;
		for(auto iter=kind_is.begin(); iter!=kind_is.end(); iter++){
			kind_cnt.push_back(iter->second);
		}
		
		ans=1;
		for(int i=0; i<kinds; i++){
			ans*=(kind_cnt[i]+1);
		}
		
		cout << ans-1 << '\n';
	}
		
	return 0;
}
