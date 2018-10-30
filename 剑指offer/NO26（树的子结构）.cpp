#include<cstdio>

struct BinaryTreeNode{
	double value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(int x){
		value=x;
	}
}; 
bool equal(double num1,double num2);
bool doesTree1HaveTree2(BinaryTreeNode* root1,BinaryTreeNode* root2);

bool hasSubTree(BinaryTreeNode* root1,BinaryTreeNode* root2){
	bool result=false;
	if(root1!=NULL&&root2!=NULL){
		if(equal(root1->value,root2->value)){
			result=doesTree1HaveTree2(root1,root2);
		}
		if(!result){
			result=hasSubTree(root1->left,root2);
		}
		if(!result){
			result=hasSubTree(root1->right,root2);
		}
	}
	return result;
}

bool doesTree1HaveTree2(BinaryTreeNode* root1,BinaryTreeNode* root2){
	if(root2==NULL){
		return true;
	}
	if(root1==NULL){
		return false;
	}
	if(!equal(root1->value,root2->value)){
		return false;
	}
	return doesTree1HaveTree2(root1->left,root2->left)&&doesTree1HaveTree2(root1->right,root2->right);
}
bool equal(double num1,double num2){
	if(num1-num2>-0.0001&&num1-num2<0.0001){
		return true;
	}else{
		return false;
	}
}
int main(){
	BinaryTreeNode* root1=new BinaryTreeNode(1);
	BinaryTreeNode* root2=new BinaryTreeNode(2);
	
	bool result=hasSubTree(root1,root2);
	return 0;
}
