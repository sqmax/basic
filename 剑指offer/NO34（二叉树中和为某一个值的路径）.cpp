#include<cstdio>
#include<vector>
using namespace std;

struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

void findPath(BinaryTreeNode* root,int expectedSum,vector<int> &path,int currentSum);
 
void findPath(BinaryTreeNode* root,int expected){
	if(root==NULL){
		return;
	}
	vector<int> path;
	int currentSum=0;
	findPath(root,expected,path,currentSum);
} 
void findPath(BinaryTreeNode* root,int expectedSum,vector<int> &path,int currentSum){
	currentSum+=root->value;
	path.push_back(root->value);
	
	bool isLeaf=root->left==NULL&&root->right==NULL;
	if(currentSum==expectedSum&&isLeaf){
		printf("A path is found:");
		vector<int>::iterator itr=path.begin();
		for(;itr!=path.end();itr++){
			printf("%d\t",*itr);
		}
		printf("\n");
	}
	if(root->left!=NULL){
		findPath(root->left,expectedSum,path,currentSum);
	}
	if(root->right!=NULL){
		findPath(root->right,expectedSum,path,currentSum);
	}
	path.pop_back();
}

int main(){
	
	return 0;
}
