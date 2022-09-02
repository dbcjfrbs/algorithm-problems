//현대자동차그룹에는 수많은 그룹사들이 존재한다.
//
//그 중에서도 서울에 위치하는 몇 개의 그룹사들을 알아보자.
//
//서초구 양재동에 현대자동차/기아 본사, 강남구 역삼동에 현대모비스, 강남구 삼성동에 현대오토에버 등 각 그룹사들은 곳곳에 흩어져 있다. 
//
//
//
//그리고 각 그룹사들의 네트워크는 보안을 위해 별도의 그룹망(VPN)으로 연결되어 있다.
//
//그룹망 설치에는 많은 비용이 드는데 모든 그룹사를 상호간 연결하려면 막대한 비용이 들기 때문에, 각 그룹사 연결 시 회선을 공유하여 모든 그룹사를 연결하되 최소 비용으로 그룹망을 구축하는 방안을 검토 중에 있다.
//
//
//
// 
//
//
//
//예를 들어, 현대/기아 본사, 현대모비스, 현대오토에버 전체를 그룹망으로 연결할 경우 비용은 16이 든다. 
//
//하지만 회선을 공유한다고 생각했을 때, 현대/기아 본사 - 현대모비스 - 현대오토에버 순으로 연결하면 총 9의 비용으로 모든 그룹사에 대한 연결이 가능하다.
//
//이처럼 각 그룹사를 연결하는 망 설치 비용(K)이 주어질 때, 모든 그룹사를 그룹망으로 연결하기 위한 최소 비용을 구해보자.
//
//제약조건
//3≤N≤100
//
//K≤105
//
//입력형식
//첫 번째 줄에 그룹사의 수 N이 주어진다.
//
//둘째 줄부터는 N x N 행렬로 그룹망 설치 비용 K 가 주어진다.
//
//이때 행렬의 i행 j열의 값은 i번 회사에서 j 번 회사를 그룹망으로 연결하기 위한 비용을 나타낸다.
//
//출력형식
//전체 그룹사들을 그룹망으로 연결하기 위한 최소 비용을 출력한다.
//
//입력예제1복사하기
//3
//067
//603
//730
//출력예제1
//9
//입력예제2복사하기
//4
//0459
//4029
//5203
//9930
//출력예제2
//9
//입력예제3복사하기
//7
//0393699
//3057181
//9503328
//3730638
//6136028
//9823206
//9188860
//출력예제3
//12





#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int parent[101];
bool visit[101];
int map[101][101];
vector<vector<int> > v; // 원소벡터에 3개의 원소가 있음. 순서대로 노드1, 노드2, 노드 1-2연결 비용

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
