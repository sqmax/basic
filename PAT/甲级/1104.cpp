#include<cstdio>

const int maxn=100010;

double a[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf",&a[i]);
	}
	double sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i]*(n-i)*(i+1);
	}
	//下面3重循环会超时 
//	for(int k=0;k<n;k++){
//		for(int i=k;i<n;i++){
//			for(int j=k;j<=i;j++){
//				sum+=a[j];
////				printf("%.1f ",a[j]);
//			}
////			printf("\n");
//		}	
//	}
	printf("%.2lf\n",sum);
	
	return 0;
} 
