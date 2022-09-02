#include <iostream>
using namespace std;

int n;
struct node{
	char data;
	node *leftChild, *rightChild;
};
node nodes[26];

void Input(){
	cin >> n;
	for(int i=0; i<n; i++){
		char a, b, c;
		cin >> a >> b >> c;
		
		nodes[a-'A'].data=a;
		
		if(b=='.') nodes[a-'A'].leftChild=NULL;
		else nodes[a-'A'].leftChild=&nodes[b-'A'];
		
		if(c=='.') nodes[a-'A'].rightChild=NULL;
		else nodes[a-'A'].rightChild=&nodes[c-'A'];
	}	
}

void PreOrder(node *Ptr){
	if(Ptr){
		cout << Ptr->data;
		PreOrder(Ptr->leftChild);
		PreOrder(Ptr->rightChild);
	}
	
	return ;
}

void InOrder(node *Ptr){
	if(Ptr){
		InOrder(Ptr->leftChild);
		cout << Ptr->data;
		InOrder(Ptr->rightChild);
	}
	
	return ;
}

void PostOrder(node *Ptr){
	if(Ptr){
		PostOrder(Ptr->leftChild);
		PostOrder(Ptr->rightChild);
		cout << Ptr->data;
	}
	
	return ;
}

int main(){
	Input();
	
	PreOrder(&nodes[0]);
	cout << '\n';	
	InOrder(&nodes[0]);		
	cout << '\n';	
	PostOrder(&nodes[0]);		
	
	return 0;
}
