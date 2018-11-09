#include<cstdio>

int main(){
	int num[10]={0};
	int minN=0;
	bool flag=false;
	for(int i=0;i<10;i++){
		int t;
		scanf("%d",&t);
		num[i]=t;
		if(t&&i&&flag==false){
			minN=i;
			flag=true;
		}
	}
	printf("%d",minN);
	num[minN]--;
	for(int i=0;i<10;i++){
		while(num[i]--){
			printf("%d",i);
		}
	}
	return 0;
}
