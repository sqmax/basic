#include<cstdio>
#include<queue>
using namespace std;

const int maxn=1010;
int cmpT[maxn],n;

void levelOrder(int root,int a[]){
	queue<int> q;
	q.push(root);
	int cnt=0;
	while(!q.empty()){
		int front=q.front();
		q.pop();
		cmpT[front]=a[cnt++];
		if(front*2<=n) q.push(front*2);
		if(front*2+1<=n) q.push(front*2+1);
	}
}
bool isMaxHeap(int root){
	if(root*2>n) return true;//没子树 
	else if(cmpT[root]>=cmpT[root*2]&&root*2+1>n) return true;//有左子树 ，没右子树 
	else if(cmpT[root]>=cmpT[2*root]&&cmpT[root]>=cmpT[2*root+1]){//左右子树都有，且根节点不小于左右子树，递归地判断左右子树是否是最大堆 
		return isMaxHeap(root*2)&&isMaxHeap(root*2+1);
	}else{
		return false;
	} 	
}
bool isMinHeap(int root){
	if(root*2>n) return true;
	else if(cmpT[root]<=cmpT[root*2]&&root*2+1>n) return true;
	else if(cmpT[root]<=cmpT[2*root]&&cmpT[root]<=cmpT[2*root+1]){
		return isMinHeap(root*2)&&isMinHeap(root*2+1);
	}else{
		return false;
	} 	
}
bool flg=false;
void postOrder(int root){
	if(root>n) return;
	if(root*2<=n) postOrder(root*2);
	if(root*2+1<=n) postOrder(root*2+1);
	if(flg==false) flg=true;
	else printf(" ");
	printf("%d",cmpT[root]);
}
int main(){
	int m;
	scanf("%d%d",&m,&n);
	while(m--){
		int a[n];
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		levelOrder(1,a);
		if(isMaxHeap(1)){
			printf("Max Heap\n");
		}else if(isMinHeap(1)){
			printf("Min Heap\n");
		}else{
			printf("Not Heap\n");
		}
		flg=false;
		postOrder(1);
		printf("\n");
	}
	return 0;	
}
