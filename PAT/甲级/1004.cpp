#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

const int maxn=110;
struct Node{
	int key;
	int layer;
	vector<int> childs;
}node[maxn]; 
int ans[maxn];
int maxL=0;

void orderTrave(int root){
	queue<int> q;
	node[root].layer=0;
	q.push(root);
	while(!q.empty()){
		int front=q.front();
		q.pop();
		if(node[front].childs.size()==0){
			ans[node[front].layer]++;			
		}
		if(node[front].layer>maxL){
			maxL=node[front].layer;
		}
		for(int i=0;i<node[front].childs.size();i++){
			int child=node[front].childs[i];
			node[child].layer=node[front].layer+1;
			q.push(child);
		}
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int id,k,child;
		scanf("%d%d",&id,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&child);
			node[id].childs.push_back(child);
		}
	}
	orderTrave(1);
	for(int i=0;i<=maxL;i++){
		printf("%d",ans[i]);
		if(i<maxL){
			printf(" ");
		}
	}
	return 0;
}
