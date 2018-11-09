#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=110;
struct Node{
	int weight;
	vector<int> childs;
}node[maxn];
int n,m,s;
int path[maxn];
bool cmp(int a,int b){
	return node[a].weight>node[b].weight;
}
void DFS(int root,int sum,int numNode){
	if(sum>s){
		return;
	}
	if(sum==s){
		if(node[root].childs.size()!=0){
			return;
		}
		for(int i=0;i<numNode;i++){
			printf("%d",node[path[i]].weight);
			if(i<numNode-1){
				printf(" ");
			}else{
				printf("\n");
			}
		}
		return;
	}
	for(int i=0;i<node[root].childs.size();i++){
		int child=node[root].childs[i];
		path[numNode]=child;
		DFS(child,sum+node[child].weight,numNode+1);
	}
}
int main(){

	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<n;i++){
		scanf("%d",&node[i].weight);
	}
	for(int i=0;i<m;i++){
		int id,k,ch;
		scanf("%d %d",&id,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&ch);
			node[id].childs.push_back(ch);
		}
		sort(node[id].childs.begin(),node[id].childs.end(),cmp);
	}
	path[0]=0;
	DFS(0,node[0].weight,1);
	
	return 0;
}

