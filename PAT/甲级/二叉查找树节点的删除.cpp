#include<cstdio>

struct Node{
	int data;
	Node* left,*right;
};
Node* findMax(Node* root){
	if(root==NULL){
		return NULL;
	}
	while(root->right){
		root=root->right;
	}
	return root;
}
Node* findMin(Node* root){
	if(root==NULL){
		return NULL;
	}
	while(root->left){
		root=root->left;
	}
	return root;
}
void deleteNode(Node* &root,int x){
	if(root==NULL){
		return;
	}
	if(root->data==x){
		if(root->left==NULL&&root->right==NULL){
			root=NULL;
		}else if(root->left!=NULL){
			Node* pre=findMax(root->left);
			root->data=pre->data;
			deleteNode(root->left,pre->data);
		}else{
			Node* next=findMin(root->right);
			root->data=next->data;
			deleteNode(root->right,next->data);
		}
	}else if(root->data>x){
		deleteNode(root->left,x);
	}else{
		deleteNode(root->right,x);
	}
}
int main(){
	
	return 0;
}
