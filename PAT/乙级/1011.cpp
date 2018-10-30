#include<cstdio>

int main(){
	long a,b,c;
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%ld%ld%ld",&a,&b,&c);
		if(a+b>c){
			printf("Case #%d: true\n",i);
		}else{
			printf("Case #%d: false\n",i);
		}
	} 
}
