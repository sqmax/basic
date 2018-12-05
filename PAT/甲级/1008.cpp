#include<cstdio>

int main(){
	int a=0,b;
	int tot=0;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&b);
		if(b>a){
			tot+=(b-a)*6;
		}else{
			tot+=(a-b)*4;
		}
		a=b;
		tot+=5;
	}
	printf("%d\n",tot);
	
	return 0;
}
