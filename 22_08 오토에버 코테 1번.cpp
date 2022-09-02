//�����ڵ����׷쿡�� ������ �׷����� �����Ѵ�.
//
//�� �߿����� ���￡ ��ġ�ϴ� �� ���� �׷����� �˾ƺ���.
//
//���ʱ� ���絿�� �����ڵ���/��� ����, ������ ���ﵿ�� ������, ������ �Ｚ���� ������信�� �� �� �׷����� ������ ����� �ִ�. 
//
//
//
//�׸��� �� �׷����� ��Ʈ��ũ�� ������ ���� ������ �׷��(VPN)���� ����Ǿ� �ִ�.
//
//�׷�� ��ġ���� ���� ����� ��µ� ��� �׷�縦 ��ȣ�� �����Ϸ��� ������ ����� ��� ������, �� �׷�� ���� �� ȸ���� �����Ͽ� ��� �׷�縦 �����ϵ� �ּ� ������� �׷���� �����ϴ� ����� ���� �߿� �ִ�.
//
//
//
// 
//
//
//
//���� ���, ����/��� ����, ������, ������信�� ��ü�� �׷������ ������ ��� ����� 16�� ���. 
//
//������ ȸ���� �����Ѵٰ� �������� ��, ����/��� ���� - ������ - ������信�� ������ �����ϸ� �� 9�� ������� ��� �׷�翡 ���� ������ �����ϴ�.
//
//��ó�� �� �׷�縦 �����ϴ� �� ��ġ ���(K)�� �־��� ��, ��� �׷�縦 �׷������ �����ϱ� ���� �ּ� ����� ���غ���.
//
//��������
//3��N��100
//
//K��105
//
//�Է�����
//ù ��° �ٿ� �׷���� �� N�� �־�����.
//
//��° �ٺ��ʹ� N x N ��ķ� �׷�� ��ġ ��� K �� �־�����.
//
//�̶� ����� i�� j���� ���� i�� ȸ�翡�� j �� ȸ�縦 �׷������ �����ϱ� ���� ����� ��Ÿ����.
//
//�������
//��ü �׷����� �׷������ �����ϱ� ���� �ּ� ����� ����Ѵ�.
//
//�Է¿���1�����ϱ�
//3
//067
//603
//730
//��¿���1
//9
//�Է¿���2�����ϱ�
//4
//0459
//4029
//5203
//9930
//��¿���2
//9
//�Է¿���3�����ϱ�
//7
//0393699
//3057181
//9503328
//3730638
//6136028
//9823206
//9188860
//��¿���3
//12





#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int parent[101];
bool visit[101];
int map[101][101];
vector<vector<int> > v; // ���Һ��Ϳ� 3���� ���Ұ� ����. ������� ���1, ���2, ��� 1-2���� ���

bool compare(vector<int> a, vector<int> b){
	return a[2]<b[2];
}

void init(){
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> map[i][j];
			v.push_back({i, j, map[i][j]});
		}
	}
	sort(v.begin(), v.end(), compare);
	
	for(int i=0; i<=100; i++) parent[i]=i;
	return ;
}

int getParent(int x){
	if(parent[x]==x) return x;
	return parent[x]=getParent(parent[x]);	
}

void unionParents(int a, int b){
	int x=getParent(a);
	int y=getParent(b);

	if(x<y){
		parent[y]=x;
	}
	else{
		parent[x]=y;
	}

	return ;
}

bool sameParent(int a, int b){
	a=getParent(a);
	b=getParent(b);
	return a==b;
}

void solve(){
	int size=v.size();
	for(int i=0; i<size; i++){
		int node1=v[i][0];
		int node2=v[i][1];
		int money=v[i][2];
		if(sameParent(node1, node2)) continue;
		
		unionParents(node1, node2);		
		k+=money;
	}

	return ;
}

int main(int argc, char** argv){
	init();
	solve();

	cout << k;
	return 0;
}
