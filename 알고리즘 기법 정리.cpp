// union-find
int getParent(int x){
	if(parent[x]==x) return x; 
	return parent[x]=getParent(parent[x]);
}

void unionParent(int a, int b){
	a=getParent(a);
	b=getParent(b);
	
	if(a<b) parent[b]=a;
	else parent[a]=b;
	
	return ;
}

bool sameParent(int a, int b){
	a=getParent(a);
	b=getParent(b);	
	return a==b;
}

//// 크루스칼 알고리즘 - 최소 신장 트리(MST)를 만들 때 가장 적은 비용으로 만드는 알고리즘이다. 
bool compare(vector<int> &a, vector<int> &b){
	return a[2]<b[2];
}

int main(){
	vector<vector<int> > v; // a node, b node, distance 순으로 담김
	sort(v.begin(), v.end(), compare);

	int parent[n];
	for(int i=0; i<n; i++) parent[i]=i;
	
	int sum=0;
	for(int i=0; i<v.size(); i++){
		if(sameParent(v[i][1], v[i][0])) continue;
		
		unionParent(v[i][0], v[i][1]);
		sum+=v[i][2];
	}
	
	
	return 0;
}

// 프림 알고리즘 


//이진트리 순회
int number=15;

struct node *treePointer;
struct node{
	int data;
	treePointer leftChild, rightChild;
} node;

void preorder(treePointer ptr){
	if(ptr){
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}
 
int main(){
	node nodes[number+1];
	for(int i=1; i<=number; i++){
		nodes[i].data=i;
		nodes[i].leftChild=NULL;
		nodes[i].rightChild=NULL;
	}
	
	for(int i=1; i<=number; i++){
		if(i/2==0){
			nodes[i/2].leftChild=&nodes[i];
		}
		else nodes[i/2].rightChild=&nodes[i];
	}
	
	return 0;
} 

// 다익스트라 - 다시보기
void dijkstra(){
	priority_queue<pair<int, int> > pq;
	pq.push({0, x});
	d[x]=0;
	
	while(!pq.empty()){
		int cur=pq.top().second, dist=-pq.top().first;
		pq.pop();

		if(d[cur]<dist) continue; // 
		if(d[cur]>k) break;
		
		int next_size=arr[cur].size(); 
		for(int i=0; i<next_size; i++){
			int next=arr[cur][i], nextdist=dist+1;
			if(nextdist<d[next]){
				d[next]=nextdist;
				pq.push({-nextdist, next});
			}
		}		
	}		
	
	return ;
}

