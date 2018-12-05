#include<cstdio>
#include<algorithm>
using namespace std;

struct Node{
	int key;
	Node* left,*right;
};
void insert(Node* &root,int x){
	if(root==NULL){
		root=new Node;
		root->key=x;
		root->left=root->right=NULL;
		return;
	}
	if(abs(x)<abs(root->key)) insert(root->left,x);
	else insert(root->right,x);
}
bool judge4(Node* root){
	if(root==NULL){
		return true;
	}else if(root->key<0){
		if(root->left!=NULL&&root->left->key<0){
			return false;
		}
		if(root->right!=NULL&&root->right->key<0){
			return false;
		}
	}
	return judge4(root->left)&&judge4(root->right);
}
int cntBlack(Node* root){
	if(root==NULL){
		return 0;
	}
	int lBlack=cntBlack(root->left);
	int rBlack=cntBlack(root->right);
	return max(lBlack,rBlack)+(root->key>=0);
}
bool judge5(Node* root){
	if(root==NULL){
		return true;
	}
	int lBlack=cntBlack(root->left);
	int rBlack=cntBlack(root->right);
	if(lBlack!=rBlack){
		return false;
	}else{
		judge5(root->left)&&judge5(root->right);
	}
}

int main(){
	int k,n;
	scanf("%d",&k);
	while(k--){
		Node* root=NULL;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			insert(root,a);	
		}
		if(root->key<0){
			printf("No\n");
		}else if(judge4(root)==false){
			printf("No\n");
		}else if(judge5(root)==false){
			printf("No\n");
		}else{
			printf("Yes\n");
		}
	}
	
	return 0;
}
