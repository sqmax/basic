#include<cstdio>

const int maxn=1010;
int a[maxn];

int main(){

	int co,eo;
	int maxEo=0;
	while(scanf("%d %d",&co,&eo)!=EOF){
		a[eo]=co;
		if(eo>maxEo){
			maxEo=eo;
		}
	}	

	bool flag=false;
	for(int i=maxEo;i>0;i--){	
		if(a[i]){
			if(flag==false){
				flag=true;
			}else{
				printf(" ");
			}
			printf("%d %d",a[i]*i,i-1);
		}
	}
	if(flag==false){
		printf("0 0");
	}
	
	return 0;
}
