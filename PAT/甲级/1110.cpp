#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;


struct Node{
	int left,right;
}node[100];
int n;

bool levelOrder(int root,int &last){
	queue<int> q;
	bool flg=false;
	int cnt=0;
	q.push(root);
	while(!q.empty()){
		int fro=q.front();
		q.pop();
		
		if(fro!=-1){
//			if(flg==true) return false;
			q.push(node[fro].left);
			q.push(node[fro].right);	
			last=fro;
			cnt++;
		}else{
//			flg=true; 
			if(cnt<n) return false;
		}
	}
	return true;
}

int main(){
	cin>>n;
	bool flg[n];
	fill(flg,flg+n,false);
	for(int i=0;i<n;i++){
		string l,r;
		cin>>l>>r;
		if(l!="-"){
			node[i].left=stoi(l);
			flg[stoi(l)]=true;
		}else{
			node[i].left=-1;
		}
		if(r!="-"){
			node[i].right=stoi(r);
			flg[stoi(r)]=true;
		}else{
			node[i].right=-1;
		} 
	}	
	int root;
	for(int i=0;i<n;i++){
		if(flg[i]==false){
			root=i;
			break;
		}
	}
	int last=0;
	if(levelOrder(root,last)){
		printf("YES %d\n",last);
	}else{
		printf("NO %d\n",root);
	}
	
	return 0;
}
