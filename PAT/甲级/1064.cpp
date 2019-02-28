#include<algorithm>
#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

const int maxn=10010;
int a[maxn],n;
int cbt[maxn],cnt=0;

void inOrder(int root){
	if(root>n) return;
	inOrder(2*root);
	cbt[root]=a[cnt++];
	inOrder(2*root+1);	
}
vector<int> ans;
void levelOrder(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int front=q.front();
		q.pop();
		ans.push_back(cbt[front]);
		if(front*2<=n) q.push(front*2);
		if(front*2+1<=n) q.push(front*2+1);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	inOrder(1);
	levelOrder(1);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i];
		if(i<ans.size()-1) cout<<" ";
	}
	
	return 0;
}
