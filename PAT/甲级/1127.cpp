#include<cstdio>
#include<queue>
#include<stack> 
using namespace std;

const int maxn=1010;
struct Node{
	int data,level;
	Node* left,*right;
};
int inOrder[maxn],postOrder[maxn];
vector<Node*> levelV;
vector<int> ans;
queue<int> ansQ;

Node* create(int inL,int inR,int postL,int postR){
	if(inL>inR){
		return NULL;
	}
	int k;
	for(int i=inL;i<=inR;i++){
		if(inOrder[i]==postOrder[postR]){
			k=i;
			break;
		}
	}
	Node* root=new Node;
	root->data=inOrder[k];
	int leftNum=k-inL;
	root->left=create(inL,k-1,postL,postL+leftNum-1);
	root->right=create(k+1,inR,postL+leftNum,postR-1);
	return root;
}
void levelOrder(Node* root){
	if(root==NULL) return;
	queue<Node*> q;
	root->level=1;
	q.push(root);
	while(!q.empty()){
		Node* front=q.front();
		q.pop();
		levelV.push_back(front);
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
void getStack(stack<int> &st){
	while(st.size()!=0){
		ans.push_back(st.top());
		st.pop();
	}
}
void zigzag(){
	stack<int> tempS;
	for(int i=0;i<levelV.size();i++){
		if(levelV[i]->level%2!=0){
			tempS.push(levelV[i]->data);
		}else{
			getStack(tempS);
			ans.push_back(levelV[i]->data);
		}
	}
	getStack(tempS);
}
void printAns(){
	for(int i=0;i<ans.size();i++){
		printf("%d",ans[i]);
		if(i<ans.size()-1){
			printf(" ");
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&inOrder[i]);
	}	
	for(int i=0;i<n;i++){
		scanf("%d",&postOrder[i]);
	}
	Node* root=create(0,n-1,0,n-1);
	levelOrder(root);
	zigzag();
	printAns();
	
	return 0;
}
