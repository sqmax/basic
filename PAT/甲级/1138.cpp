#include<cstdio>

const int MAXN=50010;
struct TNode{
	int key;
	TNode* left,*right;
};
int pre[MAXN],in[MAXN];

TNode* create(int preL,int preR,int inL,int inR){
	if(preL>preR){
		return NULL;
	}
	TNode* root=new TNode;
	root->key=pre[preL];
	int k;
	for(k=inL;k<inR;k++){
		if(in[k]==pre[preL]){
			break;
		}
	}
	int leftNum=k-inL;
	root->left=create(preL+1,preL+leftNum,inL,k-1);
	root->right=create(preL+leftNum+1,preR,k+1,inR);
	return root;
}
void postOrder(TNode* root){
	if(root->left==NULL&&root->right==NULL){
		printf("%d",root->key);
	}else if(root->left!=NULL){
		postOrder(root->left);
	}else{
		postOrder(root->right);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	TNode* root=create(0,n-1,0,n-1);
	
	postOrder(root);
	
	return 0;
}
