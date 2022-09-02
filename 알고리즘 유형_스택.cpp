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
// stack ���̺귯���� ���� 
	stack<int> s;
    
    s.push(1); // ���� �ױ� 
    s.push(2);
    s.push(3);
	print(s);    // ���ð� ��� 

    
    int tmp=s.top(); // ���� ���� �ִ� ���ڰ� Ȯ��, �Ųٷ� ��µ� ���� 
	cout << tmp << '\n';

	
	s.pop(); // ���� ���� �ִ� ���� ���� 
	print(s); 


// ����� ���� ���� 
	int ss[100], top=-1;
	
	ss[++top]=1; // ���ڽױ� 
	ss[++top]=2; 
	ss[++top]=3; 
	print2(ss, top); // ���ð� ��� 
	
	cout << ss[top] << '\n';  // ���� ���� �ִ� ���ڰ� Ȯ��
	
	top--; // ���� ���� �ִ� ���� ����
	print2(ss, top); 

	return 0;
}

