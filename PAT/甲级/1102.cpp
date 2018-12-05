#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn=15;
struct Node{
	int left,right;
}node[maxn];
bool root[maxn];
int R;

void levelOrder(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int front=q.front();
		q.pop();
		if(front!=R) printf(" ");
		printf("%d",front);
		if(node[front].left!=-1){
			q.push(node[front].left);
		}
		if(node[front].right!=-1){
			q.push(node[front].right);
		}
	}
}
bool flg=false;
void inOrder(int root){
	if(root==-1) return;
	inOrder(node[root].left);
	if(flg==false) flg=true;
	else printf(" ");
	printf("%d",root);
	inOrder(node[root].right);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char a,b;
		getchar();
		scanf("%c %c",&a,&b);
		swap(a,b);
		if(a!='-'){
			node[i].left=a-'0';
			root[a-'0']=true;
		}else{
			node[i].left=-1;
		}
		if(b!='-'){
			node[i].right=b-'0';
			root[b-'0']=true;
		}else{
			node[i].right=-1;
		}
	}
	for(int i=0;i<n;i++){
		if(root[i]==false){
			R=i;
		}
	}
	levelOrder(R);
	printf("\n");
	inOrder(R);
	
	return 0;
}
