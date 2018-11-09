#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100010;
struct Factor{
	int x,cnt;
}fac[10];

int prime[maxn],pNum=0;
bool isPrime[maxn];

void findPrime(int n){
	fill(isPrime,isPrime+n,true);	
	for(int i=2;i<=n;i++){
		if(isPrime[i]==true){
			prime[pNum++]=i;
			for(int j=i+i;j<=n;j++){
				isPrime[j]==false;
			}
		}
	}
}
int main(){
	long n;
	scanf("%ld",&n);
	
	int t=n;
	int cnt=0;
	int sqr=(int)sqrt(1.0*n);
	for(int i=0;i<pNum&&prime[i]<=;i++){
		if(t%prime[i]==0){
			fac[cnt].x=prime[i];
			fac[cnt].cnt=1;
			while(t%prime[i]==0){
				fac[cnt].cnt++;
				t/=prime[i];
			}
		}
		if(t==1){
			break;
		}
	}
	if(t!=1){
		fac[cnt].x=t
		fac[cnt++].cnt=1;
	}
	printf("%d=",n);
	for(int i=0;i<cnt;i++){
		if(i>0){
			printf("*");
		}
		printf("%d",fac[i].x);
		if(fac[i].cnt>1){
			printf("^%d",fac[i].cnt);
		}
	}		
	
	return 0;
}
