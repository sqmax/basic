#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1000010;
int prime[maxn],cnt=0;
bool isPrime[maxn]={true};

void findPrime(int n){
	fill(isPrime,isPrime+maxn,true);
	for(int i=2;i<=maxn;i++){
		if(isPrime[i]==true){
			prime[cnt++]=i;
			if(cnt>n){
				break;
			}
			for(int j=i+i;j<maxn;j+=i){
				isPrime[j]=false; 
			}
		}
	}		
}
int main(){

	int m,n;
	scanf("%d%d",&m,&n);
	findPrime(n);
	int printNum=0;
	for(int i=m-1;i<n;i++){
		printf("%d",prime[i]);
		printNum++;
		if(printNum%10==0){
			printf("\n");
		}else if(printNum<n-m+1){
			printf(" ");
		}
	}
	return 0;
} 
