#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321

typedef long long ll;
using namespace std;

int n, exp_size, num_size, op_size, nums[10], nums_[10];
ll ans=INF*(-1);
char ops[10];
string expr;
bool check_num[11], check_op[11];

void init(){
	cin >> n >> expr;
	exp_size=expr.size();
	num_size=n/2+1;
	op_size=n/2;
	
	for(int i=0; i<exp_size; i++){
		if('0'<=expr[i] && expr[i]<='9'){
			nums[i/2]=expr[i]-'0';
			nums_[i/2]=expr[i]-'0';
		}
		else ops[i/2]=expr[i];
	}
			
	return ;
}

void unify(int i){
	if(ops[i]=='+') nums[i]+=nums[i+1];
	else if(ops[i]=='-') nums[i]-=nums[i+1]; 	
	else nums[i]*=nums[i+1];
	return ;
}

void disunite(int i){	
	nums[i]=nums_[i];
	return ;
}

ll calc(int cnt){
	ll ret, i=0, j=-1;	
	while(check_num[i]) i++;
	ret=nums[i];
	
	while(cnt--){
		do{
			i++;	
		}while(check_num[i]);
		do{
			j++;	
		}while(check_op[j]);
		
		if(ops[j]=='+') ret+=nums[i];	
		else if(ops[j]=='-') ret-=nums[i];	
		else ret*=nums[i];
	}

	return ret;
}

void comb(int depth, int start, int cnt){
	if(depth==cnt){
		ll ret=calc(op_size-cnt);
		if(ans<ret){
			ans=ret;
		}

		return ;
	}
	
	if(start>op_size-1) return ;
	
	for(int i=start; i<op_size-cnt+1+depth; i++){
		check_op[i]=true;
		check_num[i+1]=true;
		unify(i);

		comb(depth+1, i+2, cnt);

		disunite(i);
		check_op[i]=false;
		check_num[i+1]=false;
	}
	
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	init();
	for(int i=0; i<=(op_size+1)/2; i++) comb(0, 0, i);
	
	cout << ans;
	return 0;
}
