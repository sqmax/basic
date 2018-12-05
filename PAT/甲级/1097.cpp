#include<cstdio>
#include<cmath>
using namespace std;

const int maxn=100010;
struct Node{
	int key;
	int add,next;
}node[maxn],list[maxn];

Node a[maxn],b[maxn];
bool flg[maxn];

int main(){
	int head,n;
	scanf("%d %d",&head,&n);
	for(int i=0;i<n;i++){
		int add,key,next;
		scanf("%d%d%d",&add,&key,&next);
		node[add].add=add;
		node[add].key=key;
		node[add].next=next;
	}
	int tmp=head;
	int cnt=0;
	while(tmp!=-1){
		list[cnt++]=node[tmp];
		tmp=node[tmp].next;
	}
	int cnt1=0,cnt2=0;
	for(int i=0;i<cnt;i++){
		if(flg[(int)abs(list[i].key)]==false){
			a[cnt1++]=list[i];
			flg[(int)abs(list[i].key)]=true;
		}else{
			b[cnt2++]=list[i];
		}
	}
//	printf("---------");
	for(int i=0;i<cnt1-1;i++){
		printf("%05d %d %05d\n",a[i].add,a[i].key,a[i+1].add);
	}
	printf("%05d %d -1\n",a[cnt1-1].add,a[cnt1-1].key);
	
	for(int i=0;i<cnt2-1;i++){
		printf("%05d %d %05d\n",b[i].add,b[i].key,b[i+1].add);
	}
	if(cnt2>0) printf("%05d %d -1",b[cnt2-1].add,b[cnt2-1].key);
	return 0;
}

