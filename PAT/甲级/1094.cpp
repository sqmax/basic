#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

const int maxn=10010;
struct Node{
	int key,level;
	vector<int> childs;
}node[maxn];
int cnt[maxn];
int maxL=0;

void levelOrder(int root){
	queue<int> q;
	node[root].level=1;
	q.push(root);
	while(!q.empty()){
		int front=q.front();
		q.pop();
		cnt[node[front].level]++;
		maxL=max(maxL,node[front].level);
		for(int i=0;i<node[front].childs.size();i++){
			int ch=node[front].childs[i];
			node[ch].level=node[front].level+1;
			q.push(ch);
		}
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int id,k;
		scanf("%d%d",&id,&k);
		for(int j=0;j<k;j++){
			int c;
			scanf("%d",&c);
			node[id].childs.push_back(c);
		}
	}
	levelOrder(1);
	int maxG=0,level;
	for(int i=1;i<=maxL;i++){
		if(cnt[i]>maxG){
			maxG=cnt[i];
			level=i;
		}
	}
	printf("%d %d\n",maxG,level);
	
	return 0;
}
