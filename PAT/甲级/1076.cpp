#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

const int MAXV=1010;
struct Node{
	int v;
	int layer;
};
int G[MAXV][MAXV]={0};
bool inq[MAXV]={false};
int n,l,k;

void BFS(int id,int& forward){
	queue<Node> q;
	Node temp;
	temp.v=id;
	temp.layer=0;
	q.push(temp);
	inq[id]=true;
	while(!q.empty()){
		Node front=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(inq[i]==false&&G[front.v][i]==1&&front.layer<l){
				Node next;
				next.v=i;
				next.layer=front.layer+1;
				q.push(next);
				inq[i]=true;
				forward++;
			}
		}
	}
}
int main(){
	scanf("%d %d",&n,&l);
	for(int i=1;i<=n;i++){
		int num,id;
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			scanf("%d",&id);
			G[id][i]=1;
		}
	}	
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int id;
		scanf("%d",&id);
		fill(inq,inq+n+1,false);
		int forward=0;
		BFS(id,forward);
		printf("%d\n",forward); 
	}
	
	return 0;
}
