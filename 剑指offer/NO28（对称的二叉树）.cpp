#include<cstdio>

struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left; 
	BinaryTreeNode* right;
};

bool isSymmetrical(BinaryTreeNode* root1,BinaryTreeNode* root2);

bool isSymmetrical(BinaryTreeNode* root){
	return isSymmetrical(root->left,root->right);
}
bool isSymmetrical(BinaryTreeNode* root1,BinaryTreeNode* root2){
	if(root1==NULL&&root2==NULL){
		return true;
	}
	if(root1==NULL||root2==NULL){
		return false;
	}
	if(root1->value!=root2->value){
		return false;
	}
	return isSymmetrical(root1->left,root2->right)&&isSymmetrical(root1->right,root2->left);
}

int main(){
	
	return 0;
}
