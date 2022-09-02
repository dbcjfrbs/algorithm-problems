#include <iostream>
#include <string.h>
#define MAX 101
using namespace std;

int n, ans;
int visit[26];
char words[MAX][MAX];

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> words[i];
		
		memset(visit, 0, sizeof(visit));
		char *str=words[i];
		int len=strlen(str);

		if(len==1){
			ans++;
			continue;
		}
		
		visit[str[0]-'a']=1;
		for(int j=0; j<len-1; j++){
			if(str[j]!=str[j+1]){
				if(visit[str[j+1]-'a']==1) break;
				visit[str[j+1]-'a']=1;
			}
			
			if(j==len-2) ans++;
		}		
	}
	
	cout << ans;
	
	return 0;
}
