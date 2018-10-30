#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

const int maxn=100010;
bool prime[maxn];
int res[maxn];
int cnt=0;
//判断一个数n是不是素数 
/** 
bool isPrime(int n){
	if(n<=1){
		return false;
	}
	for(int i=2;i<sqrt(n);i++){
		if(n%i==0){
			break;
			return false;
		}
	}
	return true;
}
*/ 
//收集n以内的素数 
void findPrime(int n){
	fill(prime,prime+maxn,true);
	for(int i=2;i<=n;i++){
		if(prime[i]==true){
			res[cnt++]=i;
		}else{
			continue;
		}
		for(int j=i+i;j<=n;j+=i){
			prime[j]=false;//素数的倍数是非素数 
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	findPrime(n);
	int ans=0;
	for(int i=0;i<cnt-1;i++){
		if(res[i+1]-res[i]==2){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
