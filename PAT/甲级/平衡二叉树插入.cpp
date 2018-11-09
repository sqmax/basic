#include<cstdio>
#include<algorithm> 
using namespace std;

struct Node{
	int data;
	int height;
	Node* left,*right;
}; 
Node* newNode(int v){
	Node* node=new Node;
	node->data=v;
	node->height=1;
	node->left=node->right=NULL;
	return node;
}
int getHeight(Node* root){
	if(root==NULL){
		return 0;
	}
	return root->height;
}
int getBalanceFactor(Node* root){
	return getHeight(root->left)-getHeight(root->right);
}
void updateHeight(Node* root){
	root->height=max(getHeight(root->left),getHeight(root->right))+1;
}
//×óÐý 
void L(Node* &root){
	Node* temp=root->right;
	root->right=temp->left;
	temp->left=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
//ÓÒÐý 
void R(Node* &root){
	Node* temp=root->left;
	root->left=temp->right;
	temp->right=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
} 
//Æ½ºâ¶þ²æÊ÷²åÈë
void insert(Node* &root,int v){
	if(root==NULL){
		root=newNode(v);
		return;
	}
	if(v<root->data){
		insert(root->left,v);
		updateHeight(root);
		if(getBalanceFactor(root)==2){
			if(getBalanceFactor(root->left)==1){
				R(root);
			}else if(getBalanceFactor(root->left)==-1){
				L(root->left);
				R(root);
			}
		}
	}else{
		insert(root->right,v);
		updateHeight(root);
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->right)==-1){
				L(root);
			}else if(getBalanceFactor(root->right)==1){
				R(root->right);
				L(root);
			}
		}
	}
} 
int main(){
	
	return 0;
}

