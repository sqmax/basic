#include<cstdio>

int main(){
	int n;
	scanf("%d",&n);
	int a,b,c;
	a=n/100;
	b=n%100/10;
	c=n%10;
	
	while(a--){
		printf("B");
	}
	while(b--){
		printf("S");
	}
	for(int i=1;i<=c;i++){
		printf("%d",i);
	}
	
	return 0;
} 
