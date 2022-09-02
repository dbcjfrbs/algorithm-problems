#include <iostream>
using namespace std;

int height_cnt[100]={0}; // index: height, data: 개수
int height[9];
bool comb(int *a, int cnt, int idx){
	if(cnt==7){
//		cout << 1;
		int sum=0;
		for(int i=0; i<7; i++)
			sum+=a[i];

		if(sum==100){
			for(int x=0; x<7; x++)
				cout << a[x] << endl;
			return 1;
		}
		else return 0;
	}

	for(int i=idx; i<cnt+3; i++){ // 8-cnt: 남은 거, 6-cnt: 남은 인자
		a[cnt]=height[i];
		if(comb(a, cnt+1, i+1)==1) return 1;
	}
	
	return 0; //이거를 안써줘서 틀렸음... 
}

int main(){
	int tmp; 
	for(int i=0; i<9; i++){
		cin >> tmp;
		height_cnt[tmp]++;
	}
	
	int t=0;
	for(int i=0; i<100; i++)
		if(height_cnt[i]==1) height[t++]=i;
	
	int a[7];
	comb(a, 0, 0);

	return 0;
}






