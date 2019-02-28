#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

const int maxn=110;
struct Node{
	vector<int> childs;
	int level;
}node[maxn];
int levelLeafN[maxn];
int maxL=-1;

void levelOrder(int root){
	queue<int> q;
	q.push(root);
	node[root].level=0;
	while(!q.empty()){
		int top=q.front();
		q.pop();
		int level=node[top].level;
		maxL=(maxL,level);
		if(node[top].childs.size()==0){
			levelLeafN[level]++;
		}
		for(int i=0;i<node[top].childs.size();i++){
			int ch=node[top].childs[i];
			q.push(node[top].childs[i]);
			node[ch].level=level+1;					
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int id,k,ch;
		cin>>id>>k;
		for(int j=0;j<k;j++){
			cin>>ch;
			node[id].childs.push_back(ch);
		}
	}
	levelOrder(1);
	for(int i=0;i<=maxL;i++){
		printf("%d",levelLeafN[i]);
		if(i<maxL) printf(" ");
	}
	return 0;
}
