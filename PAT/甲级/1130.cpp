//本体的难点是中序遍历时根之外的非叶子节点加括号 
#include<cstdio>
#include<string>
using namespace std;

const int maxn=30;
struct Node{
	char data[10];
	int left,right;
}node[maxn];
bool notRoot[maxn];
string ans;
int Root; 
void inOrder(int root){
	if(root==-1){	
		return;
	}
	bool flag=false;
	if(root!=Root){
		if(node[root].left!=-1||node[root].right!=-1){//根之外的非叶子节点加括号 
			flag=true;
		} 
	}
	if(flag){
		ans+='(';
	}
	inOrder(node[root].left);
	ans+=node[root].data;
	inOrder(node[root].right);
	if(flag){
		ans+=')';
	}	
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		getchar();
		scanf("%s %d %d",node[i].data,&node[i].left,&node[i].right);
		if(node[i].left>0) notRoot[node[i].left]=true;
		if(node[i].right>0) notRoot[node[i].right]=true;
	}
	for(int i=1;i<=n;i++){
		if(notRoot[i]==false){
			Root=i;
			break;
		}
	}
	inOrder(Root);
	printf("%s\n",ans.c_str());
	
	return 0;
}
