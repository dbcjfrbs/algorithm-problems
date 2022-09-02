#include <iostream>
#include <stack>

using namespace std;

void print(stack<int> s){
	int size=s.size();
	for(int i=0; i<size; i++){
		int tmp=s.top();
		cout << tmp << ' ';
		s.pop();
	}
	cout << '\n';
	return ;
}

void print2(int ss[], int top){
	for(int i=0; i<=top; i++){
		cout << ss[i] << ' ';
	}
	cout << '\n';	
	
	return ;
}

int main(){
// stack 라이브러리로 구현 
	stack<int> s;
    
    s.push(1); // 상자 쌓기 
    s.push(2);
    s.push(3);
	print(s);    // 스택값 출력 

    
    int tmp=s.top(); // 가장 위에 있는 상자값 확인, 거꾸로 출력됨 주의 
	cout << tmp << '\n';

	
	s.pop(); // 가장 위에 있는 상자 빼기 
	print(s); 


// 사용자 정의 구현 
	int ss[100], top=-1;
	
	ss[++top]=1; // 상자쌓기 
	ss[++top]=2; 
	ss[++top]=3; 
	print2(ss, top); // 스택값 출력 
	
	cout << ss[top] << '\n';  // 가장 위에 있는 상자값 확인
	
	top--; // 가장 위에 있는 상자 빼기
	print2(ss, top); 

	return 0;
}

