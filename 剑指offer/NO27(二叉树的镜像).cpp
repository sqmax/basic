#include<cstdio>

struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

void mirrorRecursively(BinaryTreeNode* root){
	if(root==NULL){
		return;
	}
	if(root->left==NULL&&root->right==NULL){
		return;
	}
	BinaryTreeNode* temp=root->left;
	root->left=root->right;
	root->right=temp;
	
	if(root->left){
		mirrorRecursively(root->left);
	}
	if(root->right){
		mirrorRecursively(root->right);
	}
}

int main(){
	
	BinaryTreeNode* root=new BinaryTreeNode;
	mirrorRecursively(root);
	
	return 0;
}
