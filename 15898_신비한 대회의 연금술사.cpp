// 순열로 재료 선정10 9 8, 16*16

#include <stdio.h>
using namespace std;
int n;
struct P{
	int qual; char color;
};
P gred[10][4][4], map_qual[5][5];

void perm(int k, int a[]){ // 순열 생성하기 
	if(k==3){
		solve(a)
	}
		
	return ;
}

void rotate(int gred[][][], int cnt){
	if(cnt==0){
		gred[]
	}
}

void solve(int a[]){ // 특정 순서에 대한 재료 quality 구하기 
	for(int i=0; i<3; i++){
		gred[a[i]]
	}
}

void input(){
	scanf("%d", &n);
	getchar();
	for(int i=0; i<n; i++){
		for(int j=0; j<4; j++){
			for(int k=0; k<4; k++){
				scanf("%d ", &gred[i][j][k].qual);	
			}
		}
		for(int j=0; j<4; j++){
			for(int k=0; k<4; k++){
				if(i==n-1 && j==3 && k==3){
					scanf("%c", &gred[i][j][k].color);
					break;
				}
				scanf("%c ", &gred[i][j][k].color);	
			}
		}
	}	
//	for(int i=0; i<n; i++){
//		for(int j=0; j<4; j++){
//			for(int k=0; k<4; k++){
//				printf("%d ", gred[i][j][k].qual);	
//			}
//			printf("\n");
//		}
//		for(int j=0; j<4; j++){
//			for(int k=0; k<4; k++){
//				printf("%c ", gred[i][j][k].color);	
//			}
//			printf("\n");
//		}
//		printf("\n");
//	}
	
	return ;
}

int main(){
	input();
		
	
	return 0;
} 
