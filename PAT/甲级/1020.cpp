#include<cstdio>
#include<queue>
using namespace std;

const int maxn=31;
struct Node{
	int data;
	Node* left,*right;
};
int post[maxn];
int in[maxn];

Node* create(int postL,int postR,int inL,int inR){
	if(postL>postR){
		return NULL;
	}
	Node* root=new Node;
	root->data=post[postR];
	int k;
	for(k=inL;k<inR;k++){
		if(in[k]==post[postR]){
			break;
		}
	}
	int leftNum=k-inL;
	root->left=create(postL,postL+leftNum-1,inL,k-1);
	root->right=create(postL+leftNum,postR-1,k+1,inR);
	
	return root;
}
void levelTraversal(Node* root){
	queue<Node*> q;
	q.push(root);
	int flag=false;
	while(!q.empty()){
		Node* front=q.front();
		q.pop();
		if(flag==false){
			flag=true;
		}else{
			printf(" ");
		}
		printf("%d",front->data);
		if(front->left){
			q.push(front->left);
		}
		if(front->right){
			q.push(front->right);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	Node* root=create(0,n-1,0,n-1);
	
	levelTraversal(root);
	
	return 0;
}
