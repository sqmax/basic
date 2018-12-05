#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

struct Node{
	int data,height;
	Node* left,*right; 
}; 
int getHeight(Node* root){
	if(root==NULL){
		return 0;
	}
	return root->height;
}
int getBalanceFactor(Node* root){
	if(root==NULL) return 0;
	return getHeight(root->left)-getHeight(root->right);
}
void updateHeight(Node* &root){
	if(root!=NULL){
		root->height=max(getHeight(root->left),getHeight(root->right))+1;	
	}
}
void L(Node* &root){
	Node* temp=root->right;
	root->right=temp->left;
	temp->left=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
void R(Node* &root){
	Node* temp=root->left;
	root->left=temp->right;
	temp->right=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
void insert(Node* &root,int a){
	if(root==NULL){
		root=new Node;
		root->data=a;
		root->height=1;
		root->left=root->right=NULL;
		return;
	}
	if(a<root->data){
		insert(root->left,a);
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
		insert(root->right,a);
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
bool flag=false;
void print(Node* root){
	if(root==NULL) return;
	if(flag==false){
		flag=true;	
	}else{
		printf(" ");
	}
	printf("%d",root->data);
	
}
bool isCBT(Node* root){
	queue<Node*> q;
	q.push(root);
	bool flg=true;
	while(!q.empty()){
		Node* front=q.front();
		q.pop();	
		print(front);	
		if(front!=NULL){
			q.push(front->left);
			q.push(front->right);
		}else{
			while(q.size()>0){
				Node* tmp=q.front();
				if(tmp!=NULL){
					flg=false;
					break;
				}
				q.pop();
			}
		}
	}
	return flg;
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
	if(isCBT(root)){
		printf("\nYES\n");
	}else{
		printf("\nNO\n");
	}
	
	return 0; 
}
