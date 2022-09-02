//Ç®ÀÌ1 - dp 
#include <iostream>
using namespace std;
int d[1000001];

int min(int a, int b, int c){
	if(a<b){
		if(a<c) return a;
		return c;
	}
	else{
		if(b<c) return b;
		return c;
	}
}

int solve(int n){ 
	if(n==2) return 1;
	if(n==3) return 1;
	
	if(n%3==0 && n%2==0) return d[n]=min(d[n-1], d[n/3], d[n/2])+1;
	else if(n%3==0) return d[n]=min(1000000, d[n-1], d[n/3])+1;
	else if(n%2==0) return d[n]=min(1000000, d[n-1], d[n/2])+1;
	else return d[n]=d[n-1]+1;
}

int main(){
	int n;
	cin >> n;
	
	d[2]=d[3]=1;
	for(int i=4; i<=n; i++)
		solve(i);
			
	cout << d[n];
	
	return 0;
}


///////////////////////////////////////////////////////


//Ç®ÀÌ2 - bfs Å½»ö
#include <cstdio>
#include <queue>
using namespace std;

int X;
int visit[1000001];

struct QUE{
    int p, t;
};

int BFS(void)
{
    queue<QUE> q;
    q.push({X, 0});

    while(!q.empty()) {
        int num = q.front().p, time = q.front().t;
        q.pop();

        if (num == 1) return time;
        for (int i=0; i<3; i++) {
            int A;
            if (i==0) {
                if (num%3 == 0)
                    A = num/3;
                else continue;
            }
            else if (i==1) {
                if (num%2 == 0)
                    A = num/2;
                else continue;
            }
            else A = num - 1;

            if (A < 0 || A > 1000000) continue;
            if (visit[A] == 1) continue;
            else {
                q.push({A, time+1});
                visit[num] = 1;
            }
        }
    }

    return 0;
}

int main(void)
{
    int ans = 0;

    scanf("%d", &X);

    ans = BFS();

    printf("%d\n", ans);
    return 0;
} 

/////////////////////////////////////////

//Àç±ÍÀû ±¸Çö dp
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int k,an=1000001;
int dp[1000001];
int f(int n) // n->1 ÃÖ¼Ò È½¼ö
{
    if (dp[n]!=-1) return dp[n];
    if(n==1) return 0;
    int tmp=f(n-1)+1;
    if (n%3==0) tmp=min(tmp, f(n/3)+1);
    if (n%2==0) tmp=min(tmp, f(n/2)+1);
    return dp[n]=tmp;
}
int main()
{
    scanf("%d",&k);
    memset(dp, -1, sizeof(dp));
    printf("%d",f(k));
    return 0;
} 
