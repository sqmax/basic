#include<cstdio>
#include<stack>
using namespace std;

const int maxn=35;
int pre[maxn],in[maxn];
stack<int> st;
struct Node{
	int data;
	Node* left,*right;
};
Node* create(int preL,int preR,int inL,int inR){
	if(preL>preR){
		return NULL;
	}
	int k;
	for(k=inL;k<inR;k++){
		if(in[k]==pre[preL]){
			break;
		}
	}
	Node* root=new Node;
	root->data=pre[preL];
	int leftNum=k-inL;
	root->left=create(preL+1,preL+leftNum,inL,k-1);
	root->right=create(preL+leftNum+1,preR,k+1,inR);
	
	return root;
}
bool flg=false;
void postOrder(Node* root){
	if(root==NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	if(flg==false) flg=true;
	else printf(" ");
	printf("%d",root->data);
	
}
int main(){
	int n;
	scanf("%d",&n);
	int cnt1=0,cnt2=0;
	for(int i=0;i<2*n;i++){
		char action[10];
		scanf("%s",action);
		if(action[1]=='u'){
			int a;
			scanf("%d",&a);
			st.push(a);
			pre[cnt1++]=a;
		}else{
			int top=st.top();
			st.pop();
			in[cnt2++]=top;
		}
	}
	Node* root=create(0,n-1,0,n-1);
	postOrder(root);
	
	return 0;
} 
