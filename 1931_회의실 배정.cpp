#include <iostream>
#define MAX 100001
using namespace std;
int n, ans;
struct P{
	int s, e;
};
P a[MAX];

void heapify(){
	int now, root;
	P tmp;
	for(int i=2; i<=n; i++){
		now=i;
		while(now!=1){
			root=now/2;

			if(a[now].e<a[root].e){
				tmp=a[now];
				a[now]=a[root];
				a[root]=tmp;

				now=root;
			}
			
			else break;
		}
	}
	
	return ;
}

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i].s;
		cin >> a[i].e;
	}

	heapify();
	
	int now, c;
	P tmp;
	for(int i=n; i>=1; i--){
		tmp=a[i];
		a[i]=a[1];
		a[1]=tmp;
		
		now=1;
		c=2;
		while(c<i){
			if(c+1==i && a[c].e<a[now].e){
				tmp=a[now];
				a[now]=a[c];
				a[c]=tmp;
				
				break;			
			}
			else if(c<i-1){
				int t=a[c].e < a[c+1].e ? a[c].e : a[c+1].e; 
				if(a[now].e <= t){
					break;
				}
				else if(a[now].e>t){
					if(t==a[c].e){
						tmp=a[now];
						a[now]=a[c];
						a[c]=tmp;
						
						now=c;	
					}
					else{
						tmp=a[now];
						a[now]=a[c+1];
						a[c+1]=tmp;
						
						now=c+1;
					}
					c=now*2;				
				}
			}
			else break;
			
		}
	}
	
//	for(int i=n; i>=1; i--){
//		cout << a[i].s << a[i].e << endl;
//	}
	
	int finish=-1;	
	for(int i=n; i>=1; i--){
		if(finish<=a[i].s && a[i].s!=a[i].e){
			finish=a[i].e;	
			ans++;
		}
	}
// s, e가 같은 회의 추가하기 
	for(int i=n; i>=1; i--){
//		if(a[i].s==a[i].e && t!=a[i].s){
//			t=a[i].s;
//			ans++;
//		}
		if(a[i].s==a[i].e){
			ans++;
		}
	}
			
	cout << ans;
	
	return 0;
}
