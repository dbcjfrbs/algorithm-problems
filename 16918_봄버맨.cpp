#include <iostream>
#include <queue>
using namespace std;

int r, c, n;
int time[200][200];
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
// 1�� �ø��� 
void add(){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			time[i][j]++;
		}
	}
	
	return ;
}
// ��ź ���� �� 0���� ����� 
void remove(){
	queue<pair<int, int> > q;
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(time[i][j]==4){
				time[i][j]=0;

				for(int k=0; k<4; k++){
					int ni=i+dx[k], nj=j+dy[k];

					if(ni<0 || r<=ni || nj<0 || c<=nj || time[ni][nj]==0 || time[ni][nj]==4) continue; 					
					q.push({ni, nj});
				}
			}
		}
	}
	
	while(!q.empty()){
		int x=q.front().first, y=q.front().second;
		q.pop();
		time[x][y]=0;
	}
	
	return ;
}

int main(){
	cin >> r >> c >> n;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			char ch;
			cin.get(ch);
			if(ch=='\n') cin.get(ch);			

			if(ch=='O') time[i][j]=2;
		}		
	}
// ���� 
	int t=0;
	while(t!=n+1){
		if(t==0 || t==1){
			t++;
			continue;
		}
		
		add();
		remove(); 
		
		t++;
	}
// ���	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(time[i][j]==0) cout << '.';
			else cout << 'O';
		}

		cout << '\n';
	}
	
	return 0;
}
