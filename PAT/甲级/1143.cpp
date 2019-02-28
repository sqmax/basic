//该方法测试点4超时，正确的见1143-2
//但是1143-2只使用与二叉搜索树，该方法适合于所有的二叉树 
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

const int maxn=10010;
int pre[maxn],in[maxn];
map<int,int> pos;

void LCA(int preRoot,int inL,int inR,int u,int v){
	if(inL>inR) return;
	int uInIdx=pos[u],vInIdx=pos[v];
	int inRoot=pos[pre[preRoot]];
	if(uInIdx<inRoot&&vInIdx<inRoot){
		LCA(preRoot+1,inL,inRoot-1,u,v);
	}else if(uInIdx<inRoot&&vInIdx>inRoot||(uInIdx>inRoot&&vInIdx<inRoot)){
		printf("LCA of %d and %d is %d.\n",u,v,pre[preRoot]);
	}else if(uInIdx>inRoot&&vInIdx>inRoot){
		LCA(preRoot+(inRoot-inL)+1,inRoot+1,inR,u,v);
	}else{
		if(uInIdx=inRoot){
			printf("%d is an ancestor of %d.\n",u,v);
		}else if(vInIdx==inRoot){
			printf("%d is an ancestor of %d.\n",v,u);
		}
	}
}
int main(){
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>pre[i];
		in[i]=pre[i];	
	}
	sort(in+1,in+n+1);
	for(int i=1;i<=n;i++){
		pos[in[i]]=i;
	}
	while(m--){
		int a,b;
		cin>>a>>b;
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
