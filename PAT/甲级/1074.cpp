#include<cstdio>

const int maxn=100010;
struct Node{
	int data,add,next;
}tempN[maxn],node[maxn];

int main(){
	int head,n,k;
	scanf("%d%d%d",&head,&n,&k);
	for(int i=0;i<n;i++){
		int add;
		scanf("%d",&add);
		tempN[add].add=add;
		scanf("%d%d",&tempN[add].data,&tempN[add].next);
	}
	int cnt=0;
	while(head!=-1){
		node[cnt++]=tempN[head];
		head=tempN[head].next;
	}
	n=cnt;
//	printf("------------\n");
//	for(int i=0;i<n;i++){
//		printf("%05d %d %05d\n",node[i].add,node[i].data,node[i].next);
//	}
//	printf("-----------\n");
	
	int group=n/k;
	 
	for(int i=0;i<group;i++){//i表示各组元素 
		for(int j=(i+1)*k-1;j>=i*k;j--){
			if(j>i*k){
				printf("%05d %d %05d\n",node[j].add,node[j].data,node[j-1].add);
			}else{
				printf("%05d %d ",node[j].add,node[j].data);
				if(i<group-1){//不是最后一组 
					printf("%05d\n",node[(i+2)*k-1].add);
				}else if(i==group-1&&n%k){//是最后一组，但有余，余的不用倒转 
					printf("%05d\n",node[(i+1)*k].add);
				}else{
					printf("-1\n");				
				}
			}
		}
	}
	for(int i=group*k;i<n;i++){//余下的尾巴 
		if(i<n-1) printf("%05d %d %05d\n",node[i].add,node[i].data,node[i].next);
		else printf("%05d %d -1\n",node[i].add,node[i].data);
	}
	
	return 0;
}

