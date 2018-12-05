#include<cstdio>
#include<cstring>

char dig[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
bool flag=false;
void DFS(int s){
	if(s<10){
		if(flag==false){
			flag=true;	
		}else{
			printf(" ");
		}
		printf("%s",dig[s]);
		
		return;
	}
	DFS(s/10);
	if(flag==false){
		flag=true;	
	}else{
		printf(" ");
	}
	printf("%s",dig[s%10]);
}
int main(){
	char a[110];
	scanf("%s",a);
	int sum=0;
	for(int i=0;i<strlen(a);i++){
		sum+=a[i]-'0';
	}
//	printf("%d\n",sum);
	DFS(sum);
	
	return 0;
}
