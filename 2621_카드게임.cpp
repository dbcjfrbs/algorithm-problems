#include <iostream>
using namespace std;

int color[4]={0};
int num[11]={0}; // color index -> R, G, B, Y
int ans=0;

int color_same(){ // 같은 색의 최대 개수 
	int max=0;
	for(int i=0; i<5; i++){
		if(max<color[i]) max=color[i];
	}
	
	return max;
}

int num_straight(){ // 스트레이트일 때 가장 큰 수 
	for(int i=0; i<10; i++){
		if(num[i]>1) return 0;
	}
	int i, j;
	for(i=0; i<=5; i++){
		int sum=0;
		for(j=0; j<5; j++){
			sum+=num[i+j];
			if(sum==5) return i+j;
		}
	}
	
	return 0;
}

int num_same(){ // 같은 수의 최대 개수 
	int max=0;
	for(int i=0; i<10; i++){
		if(max<num[i]) max=num[i];
	}
	return max;
}

int main(){
	char col;
	int number;
	for(int i=0; i<5; i++){
		cin >> col >> number;
		if(col=='R') color[0]++;
		else if(col=='G') color[1]++;
		else if(col=='B') color[2]++;
		else color[3]++;
		
		num[number]++;
	}
//1
	if(color_same()==5){
//		cout << 1;
		int tmp1=num_straight();
		if(tmp1) ans=900+tmp1;
	}
//2
	if(num_same()==4){
//		cout << 2;
		for(int i=9; i>=0; i--){
			if(num[i]>1){
				if(ans<800+i) ans=800+i;
				break;
			}
		}
	}
//3
	if(num_same()==3){
//		cout << 3;
		int tmp2, tmp3=-1;
		for(int i=0; i<10; i++){
			if(num[i]==3) tmp2=i;
			if(num[i]==2) tmp3=i;
		}
		if(tmp3!=-1 && ans<700+10*tmp2+tmp3) ans=700+10*tmp2+tmp3;
	}
//4		
	if(color_same()==5){
//		cout << 4;
		for(int i=9; i>=0; i--){
			if(num[i]==1 && ans<600+i){
				ans=600+i;
				break;	
			} 
		}
	}
//5
	if(num_straight()){
//		cout << 5;
		if(ans<500+num_straight())ans=500+num_straight();	
	} 
//6
	if(num_same()==3){
	//	cout << 6;
		for(int i=0; i<10; i++){
			if(num[i]==3){
				if(ans<400+i) ans=400+i;
				break;
			}
		}
	}
//7
	if(num_same()==2){
//		cout << 7;
		int cnt=0;
		int tmp7[2];
		for(int i=9; i>=0; i--){
			if(num[i]==2){
				tmp7[cnt++]=i;
			}
		}
		if(cnt==2 && ans<300+10*tmp7[0]+tmp7[1]) ans=300+10*tmp7[0]+tmp7[1];
	}
//8
	if(num_same()==2){
//		cout << 8;
		int tmp8;
		for(int i=9; i>=0; i--){
			if(num[i]==2) tmp8=i;
		}
		if(ans<200+tmp8) ans=200+tmp8;
	}
//9
	else{
//		cout << 9;
		for(int i=9; i>=0; i--){
			if(num[i]){
				if(ans<100+i) ans=100+i;
				break;
			}	
		}		
	}
	
	cout << ans;
	return 0;
} 
