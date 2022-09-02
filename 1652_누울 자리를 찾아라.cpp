#include <iostream>
using namespace std;

int N, ans1=0, ans2=0;
char room[100][100];

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> room[i];
	}
	
	int cnt;
	//행 누울 자리
	for(int i=0; i<N; i++){
		cnt=0;
		for(int j=0; j<N; j++){
			if(room[i][j]=='.'){
				cnt++;
				if(cnt==2){
					ans1++;
				}
			}
			else cnt=0;			
		}
	}
	 
	//열 누울 자리
	for(int i=0; i<N; i++){
		cnt=0;
		for(int j=0; j<N; j++){
			if(room[j][i]=='.'){
				cnt++;
				if(cnt==2){
					ans2++;
				}
			}
			else cnt=0;			
		}
	}
	cout << ans1 << " " << ans2;
	
	return 0;
} 
