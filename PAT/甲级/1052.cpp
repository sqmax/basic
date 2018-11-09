#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100010;
struct Node{
	int key,addr,next;
	bool flag;
	Node(){
		flag=false;
	}
}node[maxn];
int cnt=0;
bool cmp(Node a,Node b){
	if(a.flag==false||b.flag==false){
		return a.flag>b.flag;
	}else{
		return a.key<b.key;
	}
}
int main(){
	int n,head;
	scanf("%d %d",&n,&head);
	for(int i=0;i<n;i++){
		int addr,key,next;
		scanf("%d%d%d",&addr,&key,&next);
		node[addr].addr=addr;
		node[addr].key=key;
		node[addr].next=next;		
	}
	int cnt=0,p=head;
	while(p!=-1){
		node[p].flag=true;
		cnt++;
		p=node[p].next;
	}
	if(cnt==0){
		printf("0 -1\n");
	}else{
		sort(node,node+maxn,cmp);
		printf("%d %05d\n",cnt,node[0].addr);
		for(int i=0;i<cnt;i++){
			if(i!=cnt-1){
				printf("%05d %d %05d\n",node[i].addr,node[i].key,node[i+1].addr);
			}else{
				printf("%05d %d -1\n",node[i].addr,node[i].key);
			}
		}	
	}
} 
