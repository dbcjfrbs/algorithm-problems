#include <iostream>
using namespace std;

int n, m, k;
int arr[1000][16], prefer[1000][16]; //5점이상이면 1, 아니면 0
int a[16], ans;

// 손님수 리턴
int calc(){
    int cnt=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
        	bool flag=false;
            for(int x=0; x<k; x++){
            	if(a[x]==j) flag=true;	
			}
			if(flag) continue;
			
            if(prefer[i][j]==1){
                cnt++;
                break;
            }            
        }
    }

    return cnt;
}

// k개 만큼 메뉴 선택
void comb(int depth, int start){
	if(depth==k){
		int t=calc();
		if(ans<t) ans=t;
		
		return ;
	}
	
	for(int i=start; i<m-k+depth+1; i++){
		a[depth]=i;
		comb(depth+1, i+1);
	}
	
	return ;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=0;  i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j]>=5) prefer[i][j]=1;
        }
    }
    
    comb(0, 0);
    
    cout << ans;
    return 0;
}
