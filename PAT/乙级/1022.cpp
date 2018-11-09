#include<cstdio>

int main(){
	int a,b,d;
	scanf("%d%d%d",&a,&b,&d);
	int c=a+b;
	int res[100],cnt=0;
	while(c){
		res[cnt++]=c%d;
		c/=d;
	}
	if(cnt==0){
		printf("0");
	}else{
		for(int i=cnt-1;i>=0;i--){
			printf("%d",res[i]);
		}	
	}
	
	return 0;
}
