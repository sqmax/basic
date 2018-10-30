#include<cstdio>

int main(){
	int a,b,c;
	scanf("%d %d",&a,&b);
	c=a+b;
	if(c<0){
		printf("-");
		c=-c;
	}
	if(c/1000000>0){
		printf("%d,%03d,%03d\n",c/1000000,c%1000000/1000,c%1000);
	}else if(c/1000>0){
		printf("%d,%03d\n",c/1000,c%1000);
	}else{
		printf("%d\n",c);
	}
	return 0;
} 
