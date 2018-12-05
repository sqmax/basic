#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn=10010;
struct Node{
	int key;
	int left,right;
}node[maxn];

int in[maxn],cnt=0;
void inOrder(int root){
	if(root==-1) return;
	inOrder(node[root].left);
	node[root].key=in[cnt++];
	inOrder(node[root].right);
}
void levelOrder(int root){
	queue<int> q;
	q.push(root);
	bool flg=false;
	while(!q.empty()){
		int front=q.front();
		q.pop();
		if(flg==false) flg=true;
		else printf(" ");
		printf("%d",node[front].key);
		if(node[front].left!=-1){
			q.push(node[front].left);
		}
		if(node[front].right!=-1){
			q.push(node[front].right);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&node[i].left,&node[i].right);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	sort(in,in+n);
	
	inOrder(0);
	levelOrder(0);
	
	return 0;
}
