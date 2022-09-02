#include <iostream>
using namespace std;

int a, b;
int seq[1001];

int main(){
	cin >> a >> b;
	int i=1, idx=1;
	while(idx<=1000){
		for(int x=1; x<=i; x++){
			seq[idx]=i+seq[idx-1];
			idx++;
			
			if(idx>1000) break;
		}
		
		i++;
	}
	
	cout << seq[b]-seq[a-1];
	return 0;
}
