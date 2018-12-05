#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn=1010;
int tree[maxn];
int a[maxn];
int n;
int cnt=0;
void inOrder(int root){
	if(root>n) return;
	inOrder(root*2);
	tree[root]=a[cnt++];
	inOrder(root*2+1);
}
void levelOrder(int root){
	queue<int> q;
	q.push(root);
	bool flag=false;
	while(!q.empty()){
		int front=q.front();
		q.pop();
		if(flag==false) flag=true;
		else printf(" ");
		printf("%d",tree[front]);
		if(front*2<=n) q.push(front*2);
		if(front*2+1<=n) q.push(front*2+1);
//		if(front<=n){
//			q.push(front*2);
//			q.push(front*2+1);
//		}
	}
}
int main(){
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);		
	}
	sort(a,a+n);
	inOrder(1);
	
	levelOrder(1);
	
} 
