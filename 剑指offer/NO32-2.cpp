#include<cstdio>
#include<queue>
using namespace std;

struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right; 
}; 

void print(BinaryTreeNode* root){
	if(root==NULL){
		return;
	}
	queue<BinaryTreeNode*> nodes;
	nodes.push(root);
	int nextLevel=0;
	int toBePrinted=1;
	while(!nodes.empty()){
		BinaryTreeNode* front=nodes.front();
		printf("%d",front->value);
		if(front->left){
			nodes.push(front->left);
			nextLevel++;
		}
		if(front->right){
			nodes.push(front->right);
			nextLevel++;
		}
		nodes.pop();
		--toBePrinted;
		if(toBePrinted==0){
			printf("\n");
			toBePrinted=nextLevel;
			nextLevel=0;
		}
		
	}	
}
int main(){
	
	
	return 0;
}
