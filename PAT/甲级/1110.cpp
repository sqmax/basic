//3个测试点错误，快疯了，求助 
#include<cstdio>
#include<queue>
#include<vector> 
using namespace std;

const int maxn=110;
struct Node{
	int left,right;
}node[maxn]; 
int root[maxn];
vector<int> levelList;

void levelOrder(int root,bool &isComplete,int &last){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int front=q.front();
		q.pop();
		levelList.push_back(front);
		if(front!=-1){
			q.push(node[front].left);
			q.push(node[front].right);
			last=front;
		}else{
			while(!q.empty()){
				int tmp=q.front();
				q.pop();
				if(tmp!=-1){
					isComplete=false;
					return;
				}
			}
		}
	}	
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char a,b;
		getchar();
		scanf("%c %c",&a,&b);
		if(a=='-'){
			node[i].left=-1;
		}else{
			node[i].left=a-'0';
			root[a-'0']=true;
		}
		if(b=='-'){
			node[i].right=-1;
		}else{
			node[i].right=b-'0';
			root[b-'0']=true;
		}
	}
	int R;
	for(int i=0;i<n;i++){
		if(root[i]==false){
			R=i;
			break;	
		}
	}
	int last=0;
	bool isComplete=true;
	levelOrder(R,isComplete,last);
	
	if(isComplete) printf("YES %d\n",levelList[n-1]);
	else printf("NO %d\n",R);
	
	return 0;
}
