#include <iostream>
#include <string>
using namespace std;

int k, arr[10];
bool visit[10];
char seq[10];
string maxx="0", minn="10000000000";

void Init();
void Dfs(int cnt);
void Solve();

int main(){
	Init();
	Dfs(0);
	
	cout << maxx << '\n' << minn;
	
	return 0;
}

void Init(){
	cin >> k;
	for(int i=0; i<k; i++) cin >> seq[i];
	
	return ;
}

void Dfs(int cnt){
	if(cnt==k+1){
		Solve();
		return ;
	}
	
	for(int i=0; i<10; i++){
		if(visit[i]) continue;
		
		arr[cnt]=i;
		
		visit[i]=true;
		Dfs(cnt+1);		
		visit[i]=false;
	}
	
	return ;
}

void Solve(){
	for(int i=0; i<k; i++){
		if(seq[i]=='<'){
			if(!(arr[i]<arr[i+1])) return ; 
		}
		else{
			if(!(arr[i]>arr[i+1])) return ; 
		}
	}
	
	string s="";
	for(int i=0; i<=k; i++) s+=to_string(arr[i]);
	
	long long val=stoll(s), maxxx=stoll(maxx), minnn=stoll(minn);
	if(maxxx<val) maxx=s;
	if(minnn>val) minn=s;	 
	
	return ;
}
