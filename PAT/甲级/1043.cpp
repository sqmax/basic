#include<cstdio>
#include<vector>
using namespace std;

struct Node{
	int data;
	Node* left,*right;
};
void insert(Node* &root,int data){
	if(root==NULL){
		root=new Node;
		root->data=data;
		root->left=root->right=NULL;
		return;
	}
	if(data<root->data){
		insert(root->left,data);	
	}else{
		insert(root->right,data);
	}
}
void preTravasal(Node* root,vector<int> &pre){
	if(root==NULL){
		return;
	}
	pre.push_back(root->data);
	preTravasal(root->left,pre);
	preTravasal(root->right,pre);
}
void preTravasalM(Node* root,vector<int> &preM){
	if(root==NULL){
		return;
	}
	preM.push_back(root->data);
	preTravasalM(root->right,preM);
	preTravasalM(root->left,preM);
}
void postTravasal(Node* root,vector<int> &post){
	if(root==NULL){
		return;
	}
	postTravasal(root->left,post);
	postTravasal(root->right,post);
	post.push_back(root->data);
}
void postTravasalM(Node* root,vector<int> &postM){
	if(root==NULL){
		return;
	}
	postTravasalM(root->right,postM);
	postTravasalM(root->left,postM);
	postM.push_back(root->data);
}
 
int main(){
	int n;
	scanf("%d",&n);
	vector<int> origin;
	Node* root=NULL;
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		insert(root,t);
		origin.push_back(t);
	} 
	vector<int> pre,preM,post,postM;
	preTravasal(root,pre);
	preTravasalM(root,preM);
	if(origin==pre){
		postTravasal(root,post);
		printf("YES\n");
		for(int i=0;i<post.size();i++){
			printf("%d",post[i]);
			if(i<post.size()-1){
				printf(" ");
			}
		}
	}else if(origin==preM){
		postTravasalM(root,postM);
		printf("YES\n");
		for(int i=0;i<postM.size();i++){
			printf("%d",postM[i]);
			if(i<postM.size()-1){
				printf(" ");
			}
		}
	}else{
		printf("NO\n");
	}
	
	
	return 0;
}
