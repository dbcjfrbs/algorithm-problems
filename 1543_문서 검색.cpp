#include <iostream>
#include <string>
using namespace std;

string doc, ptr;
int cnt;

int main(){
	getline(cin, doc);
	getline(cin, ptr);
	
	int d_size=doc.size(), p_size=ptr.size();
	for(int i=0; i<d_size; i++){
		for(int j=0; j<p_size; j++){
			if(i+j<d_size && doc[i+j]==ptr[j]){
				if(j==p_size-1){
					cnt++;
					i+=j;
				}
			}
			else break;
		}
	}
	
	cout << cnt;
	return 0;
}
