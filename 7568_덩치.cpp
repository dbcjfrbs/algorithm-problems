#include <iostream>
#define MAX 50
using namespace std;
int n, weight[MAX], height[MAX], ans[MAX]; // ans 1�� �ʱ�ȭ�� �� �ȵ���? 

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> weight[i] >> height[i];	
		ans[i]=1;
	}
	
	for(int i=0; i<n-1; i++){
		for(int j=i; j<n; j++){
			if(weight[i]<weight[j] && height[i]<height[j]) ans[i]++;
			if(weight[i]>weight[j] && height[i]>height[j]) ans[j]++;
		}
	}
	
	for(int i=0; i<n; i++){
		cout << ans[i] << ' ';
	}	
	
	
	return 0;
}
