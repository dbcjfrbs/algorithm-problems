#include <iostream>
#include <string>
using namespace std;

int n, k, ans;
bool check[26];
string ss[50];

void Input();
void Comb(int depth, int start);
int Calc(int x);

int main(){
	Input();	
	if(k<5){
		cout << 0;
		return 0;	
	}

	k-=5;	
	Comb(0, 0);
	
	cout << ans;
	
	return 0;
}

void Input(){
	cin >> n >> k;
	for(int i=0; i<n; i++) cin >> ss[i];
	
	char primary[5]={'a', 'n', 't', 'c', 'i'};
	for(int i=0; i<5; i++) check[primary[i]-'a']=true;
}

void Comb(int depth, int start){
	if(depth==k){
		int t=Calc(n);
		if(ans<t) ans=t;

		return ;
	}	
	
	for(int i=start; i<26-k+1+depth; i++){
		if(check[i]) continue;

		check[i]=true;
		Comb(depth+1, i+1);
		check[i]=false;
	}
	
	return ;
}

int Calc(int x){
	for(int i=0; i<n; i++){
		string s=ss[i];
		int s_size=s.size();
		for(int j=0; j<s_size; j++){
			if(!check[s[j]-'a']){
				x--;
				break;
			}
		}	
	}
	
	return x;
}
