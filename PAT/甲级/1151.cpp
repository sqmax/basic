#include<cstdio>
#include<vector>
using namespace std;

const int maxn=100010;
int in[maxn],pre[maxn];
int pos[maxn]; 

void LCA(int preRoot,int inL,int inR,int u,int v){
	if(inL>inR) return;
	//inRoot,u,v:根节点,u,v在中序遍历的位置
	int inRoot=pos[pre[preRoot]],uInIdx=pos[u],vInIdx=pos[v];
	if(uInIdx<inRoot&&vInIdx<inRoot){//u,v在中序遍历中的位置小于根 
		LCA(preRoot+1,inL,inRoot-1,u,v);
	}else if((uInIdx<inRoot&&vInIdx>inRoot)
			||(uInIdx>inRoot&&vInIdx<inRoot)){
			printf("LCA of %d and %d is %d.\n",u,v,in[inRoot]);
	}else if(uInIdx>inRoot&&vInIdx>inRoot){
		LCA(preRoot+1+(inRoot-inL),inRoot+1,inR,u,v);
	}else{
		if(uInIdx==inRoot){
			printf("%d is an ancestor of %d.\n",u,v);
		}else if(vInIdx==inRoot){
			printf("%d is an ancestor of %d.\n",v,u);
		}
	}
}

int main(){
	int M,N;
	scanf("%d%d",&M,&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&in[i]);
		pos[in[i]]=i;
	}	
	for(int i=1;i<=N;i++){
		scanf("%d",&pre[i]);
	}
	
	while(M--){
		int a,b;
		scanf("%d%d",&a,&b);
		if(pos[a]&&pos[b]){
			LCA(1,1,N,a,b);
		}else if(pos[a]){
			printf("ERROR: %d is not found.\n",b);
		}else if(pos[b]){
			printf("ERROR: %d is not found.\n",a);
		}else{
			printf("ERROR: %d and %d are not found.\n",a,b);	
		}
	}
	
	return 0;
}
