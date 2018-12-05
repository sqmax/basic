#include<cstdio>

int main(){
	long long g1,s1,k1;
	long long g2,s2,k2;
	scanf("%lld.%lld.%lld %lld.%lld.%lld",&g1,&s1,&k1,&g2,&s2,&k2);
	long long t1=g1*17*29+s1*29+k1;
	long long t2=g2*17*29+s2*29+k2;
	long long t3=t1+t2;
	long long g3,s3,k3;
	g3=t3/29/17,s3=t3%(29*17)/29,k3=t3%(29*17)%29;
	
	printf("%lld.%lld.%lld\n",g3,s3,k3);
	
	return 0;
} 
