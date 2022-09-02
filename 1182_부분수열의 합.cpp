#include <iostream>
#include <algorithm>
using namespace std;

int n, s, ans;
int seq[20], a[20];

void comb(int depth, int start, int cnt){
	if(depth==cnt){
		int sum=0;
		for(int i=0; i<cnt; i++) sum+=a[i];
		if(sum==s){
			ans++;
//			for(int i=0; i<cnt; i++) cout << a[i] << ' ';
//			cout << endl;
		}
			
		return ;
	}
	
	for(int i=start; i<n-cnt+depth+1; i++){
		a[depth]=seq[i];
		comb(depth+1, i+1, cnt);
	}
	
	return ;
}

int main(){
	cin >> n >> s;	
	for(int i=0; i<n; i++) cin >> seq[i];
	
	for(int i=1; i<=n; i++){
		comb(0, 0, i);
	}
	
	cout << ans;
	
	return 0;
}

/////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int ans;
int n, s;
int a[20];

void g(int index, int sum){
    if (index==0){
        if(sum==s) ans++;
        if(sum+a[0]==s) ans++;
    }
    else{
        g(index-1,sum+a[index]);
        g(index-1,sum);
    }
    return;
}

int main(){
    cin >> n >> s;
    for(int i=0;i<n;i++) cin >> a[i];
    g(n-1,0);
    if(s==0) ans-=1;
    cout << ans;
    return 0;
}
 
