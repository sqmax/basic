#include<cstdio>

const int maxn=1010;
int coin[maxn];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		coin[a]++;
	}	
	int v1=-1;
	for(int i=0;i<maxn;i++){//一定要注意这里是maxn，不是n。一定要细心，注意循环边界，出过很多次这样的错误，考试注意 
		if(coin[i]>0){
			coin[i]--;
			if(coin[m-i]>0){
				v1=i;
				break;
			}
		}
	}
	if(v1==-1) printf("No Solution\n");
	else printf("%d %d\n",v1,m-v1);
	
	return 0;
}
