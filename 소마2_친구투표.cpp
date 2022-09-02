#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n, m, k, except;
int score[100001], visit[100001];
vector<int> friends[100001];

int calc(int x, int &sum, int &cnt){
	visit[x]=1;
	sum+=score[x];
	
	int len=friends[x].size();
	for(int i=0; i<len; i++){
		int nx=friends[x][i];
		
		if(visit[nx]==1) continue;
		calc(nx, sum, ++cnt);
	}
	
	if(cnt==0) return 0;
	else return sum/cnt;	
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    
    int x;
    for(int i=0; i<m; i++) cin >> x >> score[x];
    for(int i=0; i<k; i++){
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

	for(int i=1; i<=n; i++){
		if(score[i]!=0) continue;
		
		int sum=0, cnt=0;
		score[i]=calc(i, sum, cnt);
		if(score[i]==0) except++;
	}    
	
	int total=0;
	for(int i=1; i<=n; i++){
		total+=score[i];
	}   
	
	double ans=(double)total/(double)(n-except)*(double)100;
	ans=floor(ans);
	ans=ans/(double)100;
	cout << ans;
	
	return 0;
}
