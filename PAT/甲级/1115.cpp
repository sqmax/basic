#include<cstdio>
#include<queue>
using namespace std;

const int maxn=1010;
struct Node{
	int data,level;
	Node* left,*right;
};
int numOfEachLevel[maxn];
int maxLevel;

void insert(Node* &root,int data){
	if(root==NULL){
		root=new Node;
		root->data=data;
		root->left=root->right=NULL;
		return;
	}
	if(data<=root->data){
		insert(root->left,data);
	}else{
		insert(root->right,data);
	}
}
void levelOrder(Node* root){
	queue<Node*> q;
	root->level=1;
	q.push(root);
	while(!q.empty()){
		Node* front=q.front();
		numOfEachLevel[front->level]++;
		if(front->level>maxLevel){
			maxLevel=front->level;
		}
		q.pop();
		if(front->left){
			front->left->level=front->level+1;
			q.push(front->left);
		}
		if(front->right){
			front->right->level=front->level+1;
			q.push(front->right);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	Node* root=NULL;
	while(n--){
		int a;
		scanf("%d",&a);
		insert(root,a);
	}
	levelOrder(root);
	int a=numOfEachLevel[maxLevel];
	int b=numOfEachLevel[maxLevel-1];
	printf("%d + %d = %d",a,b,a+b);
	
	return 0;
}
