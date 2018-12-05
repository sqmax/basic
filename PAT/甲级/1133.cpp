#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100010;
struct Node{
	int add,data,next;
	int flag;
	int seq;
}node[maxn],node1[maxn];

bool cmp(Node a,Node b){
	if(a.flag!=b.flag){
		return a.flag<b.flag;
	}else{
		return a.seq<b.seq;
	}
}
int main(){
	int head,n,k;
	scanf("%d%d%d",&head,&n,&k);
	for(int i=0;i<n;i++){
		int add,data,next;
		scanf("%d%d%d",&add,&data,&next);
		node[add].add=add;
		node[add].data=data;
		node[add].next=next;
		if(data<0){
			node[add].flag=0;
		}else if(data<=k){
			node[add].flag=1;
		}else{
			node[add].flag=2;
		}
	} 
	int cnt=0;
	while(head!=-1){
		node1[cnt]=node[head];
		node1[cnt].seq=cnt;
		head=node[head].next;
		cnt++;
	}
	sort(node1,node1+cnt,cmp);
	for(int i=0;i<cnt;i++){
		printf("%05d %d ",node1[i].add,node1[i].data);
		if(i<cnt-1){
			printf("%05d\n",node1[i+1].add);
		}else{
			printf("-1\n");
		}
	}
	
	return 0;
}
