#include<cstdio>
#include<cmath>

int main(){
	int n;
	scanf("%d",&n);
	if(n<4){
		printf("1\n");
		printf("%d\n",n);
		return 0;
	}
	int maxLen=0,startPos=0;
	for(int i=2;i<=sqrt(n);i++){
		int j=i,tmp=n;
		while(true){
			if(tmp%j==0){
				tmp/=j;
				j++;
			}else{
				break;
			}
		}
		if(j-i>maxLen){
			startPos=i;
			maxLen=j-i; 
		}
	}
	if(maxLen==0){
		printf("1\n");
		printf("%d\n",n);
	}else{
		printf("%d\n",maxLen);
		printf("%d",startPos);
		for(int i=startPos+1;i<startPos+maxLen;i++){
			printf("*%d",i);
		}
	}
	
	return 0;
}
