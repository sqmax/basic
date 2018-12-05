#include<cstdio>
#include<cmath>

int reverseInDRadix(int n,int d){
	int rnt=0;
	while(n>0){
		rnt=rnt*d+n%d;
		n/=d;
	}
	return rnt;
}
bool isPrime(int x){
	if(x<=1) return false;
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0) return false;
	}
	return true;
} 
int main(){
	while(true){
		int n,d;
		scanf("%d",&n);
		if(n<0) break;
		scanf("%d",&d);
		int rev=reverseInDRadix(n,d);
		if(isPrime(n)&&isPrime(rev)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	
	return 0;
} 
