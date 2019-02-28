#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int* pre,*in;
map<int,int> pos;

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
	int m,n;
	scanf("%d%d",&m,&n);
	in=new int[n+1];
	pre=new int[n+1];
	for(int i=1;i<=n;i++){
		scanf("%d",&in[i]);
		pos[in[i]]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&pre[i]);
	}
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		if(pos[a]==0&&pos[b]==0){
			printf("ERROR: %d and %d are not found.\n",a,b);
		}else if(pos[a]==0){
			printf("ERROR: %d is not found.\n",a);
		}else if(pos[b]==0){
			printf("ERROR: %d is not found.\n",b);
		}else{
			LCA(1,1,n,a,b);
		}
	}
	return 0;
}
