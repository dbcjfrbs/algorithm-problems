#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h> // memset 
#include <math.h> 
#include <queue>
#define INF 987654321
using namespace std;

string input[4]={"0110011", "000111", "1011", "10101110101"}; // 1 0 2 3
int ans;

void update(vector<int> check_idx, string s, int s_size){
	cout << s << " ";
//�ʱ�ȭ 
	bool visit[s_size];
	vector<int> check_idx2;
	int checkpoint=-1;
	string ns="";
	int check_size=check_idx.size();
	
	for(int i=0; i<s_size; i++) visit[i]=false;
//
	if(s_size==1){
		ans=1;
		return ;
	}
	
	int dif=-2;
	for(int i=0; i<check_size; i++){
		int x=check_idx[i];
		// �������ų� �������̶�� 
		if(visit[x]) continue;
		if(x==s_size-1){
			ns+=s[x];
			break;
		}
		// ù checkpoint ������ ���ڿ� ��ġ��
		if(x!=0 && i==0) ns+=s.substr(0, x); 		
		// ���� ���ڿ� ���ٸ� 
		if(s[x]==s[x+1]){
			if(i==check_size-1) ns+=s.substr(x);
			else ns+=s.substr(x, check_idx[i+1]-x); 
		}
		// ���� ���ڿ� �ٸ��ٸ�
		else{
			
			
			visit[x]=true;
			visit[x+1]=true;
			// checkpoint ���� 
			if(x!=0){
				checkpoint=x-1;
				dif+=2;
				
				if(!visit[x-1]) check_idx2.push_back(checkpoint-dif);
			}
			// ���� checkpoint ������ ���ڿ� ���̱�
			if(i+1==s_size-1) break;
			if(i==check_size-1) ns+=s.substr(x+2);
			else ns+=s.substr(x+2, check_idx[i+1]-x-2);
		} 
	}
	// ������ ���� ���ٸ�
	if(checkpoint==-1) ans=s_size;
	// �������ٸ�
	else update(check_idx2, ns, ns.size()); 

	return ;	
}

void solution(int x){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);		
	
	ans=0;
	
	string s=input[x], ns="";
	int size=s.size();
	vector<int> check_idx;
	int dif=0;
	for(int i=0; i<size; i++){
		if(i<size-1 && s[i]!=s[i+1]){
			if(i!=0){
				check_idx.push_back(i-1-dif);
			}		
			while(i<size-1 && s[i]!=s[i+1]){
				i+=2;
				dif+=2;
			}
		}
		
		ns+=s[i];
	}
	
	update(check_idx, ns, ns.size());
	cout << endl;
	cout << "ans : " << ans << endl;
	return ;
}

int main(){
	for(int i=0; i<4; i++) solution(i);
	return 0;
}
