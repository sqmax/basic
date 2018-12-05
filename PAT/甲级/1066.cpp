#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=21;
struct Node{
	int data,height;
	Node* left,*right;
}; 
int getHeight(Node* root){
	if(root==NULL) return 0;
	return root->height;
}
void updateHeight(Node* root){
	if(root==NULL) return;
	root->height=max(getHeight(root->left),getHeight(root->right))+1;
}
int getBalanceFactor(Node* root){
	if(root==NULL) return 0;
	return getHeight(root->left)-getHeight(root->right);
}
void R(Node* &root){
	Node* temp=root->left;
	root->left=temp->right;
	temp->right=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
void L(Node* &root){
	Node* temp=root->right;
	root->right=temp->left;
	temp->left=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
void insert(Node* &root,int data){
	if(root==NULL){
		root=new Node;
		root->data=data;
		root->height=1;//注意这里是1，不是0，NULL节点的高度才是0，否则会出错 
		root->left=root->right=NULL;
		return;
	}
	if(data<root->data){
		insert(root->left,data);
		updateHeight(root);
		if(getBalanceFactor(root)==2){
			if(getBalanceFactor(root->left)==1){
				R(root);
			}else{
				L(root->left);
				R(root);
			}
		}
	}else{
		insert(root->right,data);
		updateHeight(root);
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->right)==-1){
				L(root);
			}else{
				R(root->right);
				L(root);
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	Node* root=NULL;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		insert(root,a);
	}
	printf("%d\n",root->data);
	
	return 0;
}
