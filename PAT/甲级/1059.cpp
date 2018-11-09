#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn=100010;
struct Factor{
	int x,cnt;
}fac[10];

int prime[maxn],pNum=0;
bool isPrime[maxn];

void findPrime(int n){
	fill(isPrime,isPrime+maxn,true);	
	for(int i=2;i<=maxn;i++){
		if(isPrime[i]==true){
			prime[pNum++]=i;
			for(int j=i+i;j<=maxn;j+=i){
				isPrime[j]=false;
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	if(n==1){
		printf("1=1");
		return 0;
	}
	findPrime(n);

	int t=n;
	int num=0;
	int sqr=(int)sqrt(1.0*n);
	for(int i=0;i<pNum&&prime[i]<=sqr;i++){
		if(t%prime[i]==0){
			fac[num].x=prime[i];
			fac[num].cnt=0;
			while(t%prime[i]==0){
				fac[num].cnt++;
				t/=prime[i];
			}
			num++;
		}
		if(t==1){
			break;
		}
	}
	if(t!=1){
		fac[num].x=t;
		fac[num++].cnt=1;
	}
	printf("%d=",n);
	for(int i=0;i<num;i++){
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
