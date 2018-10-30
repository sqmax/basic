#include<cstdio>

int countNum(long a,int da){
	int res=0;
	while(a>0){
		int t=a%10;
		a/=10;
		if(t==da){
			res=res*10+da;
		}
	}
	
	return res;
}
int main(){
	long a,b;
	int da,db;
	scanf("%ld %d %ld %d",&a,&da,&b,&db);
	int pa=countNum(a,da);
	int pb=countNum(b,db);
	
	printf("%d\n",pa+pb);
	
	return 0;	
} 
