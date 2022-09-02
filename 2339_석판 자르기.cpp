#include <iostream>
#include <vector>
#define MAX 20
using namespace std;

int n, arr[MAX][MAX];

int slice(int sx, int sy, int ex, int ey, int dir){
	int tresure=0; // ���� ���� 
	vector<pair<int, int> > trash; // �Ҽ��� ��ǥ �迭 
	
	for(int i=sx; i<=ex; i++){
		for(int j=sy; j<=ey; j++){
			if(arr[i][j]==1) trash.push_back({i, j});
			else if(arr[i][j]==2) tresure++;
		}
	}
// ���̻� �ɰ� �� ���� ��� 
	if(tresure==0) return 0;
	if(tresure==1 && trash.size()!=0) return 0;
	if(tresure==1 && trash.size()==0) return 1;
	if(trash.size()==0) return 0;

// �ɰ� �� �ִ� ���
	int ret=0; // ���ϰ� 
	if(dir!=2){ // ������ ���
		int len=trash.size();
		for(int j=0; j<len; j++){
			bool flag=1; int x=trash[j].first; int y=trash[j].second;
			for(int i=sy; i<=ey; i++) 
				if(arr[x][i]==2){
					flag=0;
					break;
				}
				
			if(flag) ret+=slice(sx, sy, x-1, ey, 2)*slice(x+1, sy, ex, ey, 2);				
		}
	} 
	if(dir!=1){ // ������ ���
		int len=trash.size();
		for(int j=0; j<len; j++){
			bool flag=1; int x=trash[j].first; int y=trash[j].second;
			for(int i=sx; i<=ex; i++) 
				if(arr[i][y]==2){
					flag=0;
					break;
				}
				
			if(flag) ret+=slice(sx, sy, ex, y-1, 1)*slice(sx, y+1, ex, ey, 1);			
		} 
	} 
	
	return ret;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> arr[i][j];
	
	int ans=slice(0, 0, n-1, n-1, 0);
	cout << (ans==0 ? -1 : ans); // �� ��ȣ ������ ���� ���� �ٸ���? 0, 1 
	
	return 0;
} 
