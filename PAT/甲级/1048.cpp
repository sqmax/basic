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
	for(int i=0;i<maxn;i++){//һ��Ҫע��������maxn������n��һ��Ҫϸ�ģ�ע��ѭ���߽磬�����ܶ�������Ĵ��󣬿���ע�� 
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
