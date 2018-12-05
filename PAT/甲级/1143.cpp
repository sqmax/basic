#include<cstdio>
#include<algorithm>
#include <set>
using namespace std;

struct Node{
	int data;
	Node* left,*right;
};
void insert(Node* &root,int a){
	if(root==NULL){
		root=new Node;
		root->data=a;
		root->left=root->right=NULL;
		return;
	}
	if(a<root->data){
		insert(root->left,a);
	}else{
		insert(root->right,a);
	}
}

bool search(Node* root,int a){
	if(root==NULL){
		return false;
	}
	if(a<root->data){
		search(root->left,a);
	}else if(a>root->data){
		search(root->right,a);
	}else{
		return true;
	}
}
void LCA(Node* root,int a,int b,bool changed){
	if(root!=NULL){
		if(a<root->data&&b>root->data){
			if(changed){
				printf("LCA of %d and %d is %d.\n",b,a,root->data);	
			}else{
				printf("LCA of %d and %d is %d.\n",a,b,root->data);
			}
		}else if(a==root->data){
			printf("%d is an ancestor of %d.\n",a,b);
			
		}else if(b==root->data){
			printf("%d is an ancestor of %d.\n",b,a);
		}else if(a>root->data){
			LCA(root->right,a,b,changed);
		}else{
			LCA(root->left,a,b,changed);
		}
	}
}
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	Node* root=NULL;
	set<int> s;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		insert(root,a);
		s.insert(a);
	}
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
//		bool flag1=search(root,a);
//		bool flag2=search(root,b);
		bool flag1=s.find(a)!=s.end();
		bool flag2=s.find(b)!=s.end();
		if(!flag1&&!flag2){
			printf("ERROR: %d and %d are not found.\n",a,b);
		}else if(!flag1){
			printf("ERROR: %d is not found.\n",a);
		}else if(!flag2){
			printf("ERROR: %d is not found.\n",b);
		}else{
			bool changed=false;
			if(a>b){
				swap(a,b);
				changed=true;
			}
			LCA(root,a,b,changed); 
		}		
	}
	return 0;
}
