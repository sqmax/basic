#include<cstdio>

const int maxn=10010;
int a[maxn],dp[maxn];
int st[maxn]={0};

int main(){
	int k;
	scanf("%d",&k);
	bool flag=false;
	for(int i=0;i<k;i++){
		scanf("%d",&a[i]);
		if(a[i]>=0){
			flag=true;
		}
	}
	if(flag==false){
		printf("0 %d %d\n",a[0],a[k-1]);
		return 0;
	}
	dp[0]=a[0];
	for(int i=1;i<k;i++){
		if(dp[i-1]+a[i]>a[i]){
			dp[i]=dp[i-1]+a[i];
			st[i]=st[i-1];
		}else{
			dp[i]=a[i];
			st[i]=i;
		}
	}
	int p=0;
	for(int i=1;i<k;i++){
		if(dp[i]>dp[p]){
			p=i;
		}
	}
	printf("%d %d %d\n",dp[p],st[p],p);
	return 0;
} 
