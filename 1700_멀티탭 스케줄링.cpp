#include <iostream>
using namespace std;
int n, k;
int order[100], tab[100], visit[101]={0};
int ans=0;

int rm_tab_idx(int idx){
	int cnt=0;
	for(int i=idx; i<k; i++){
		if(visit[order[i]]==ans){
			cnt++;
			visit[order[i]]+=1;
		}
		if(cnt==n){
			for(int j=0; j<n; j++){
				if(tab[j]==order[i]) return j;
			}
		}
		if(i==k-1){
			int ret;
			for(int j=0; j<n; j++){
				if(visit[tab[j]]==ans){
					ret=j;
					visit[tab[j]]+=1;
				}
			}
			
			return ret;
		}
	}
}

int main(){
	cin >> n >> k;
	int t=0;
	for(int i=0; i<k; i++){
		cin >> order[i];
		if(!visit[order[i]] && t<n){
			tab[t++]=order[i]; // tab »ı¼º
			visit[order[i]]=1;
		}
	}
	
	for(int i=0; i<k; i++){
		if(!visit[order[i]]){
			ans++;
			int tmp=rm_tab_idx(i);
			visit[tab[tmp]]=0;
			tab[tmp]=order[i];
			visit[tab[tmp]]=ans+1;
		}
	}
	cout << ans;
	
	return 0;
}
