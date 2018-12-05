#include<cstdio>
#include<cstring>

int main(){
	int n;
	scanf("%d",&n);
	char num[10];
	while(n--){
		long a=0,b=0,c=0;
		scanf("%s",num);
		int len=strlen(num);
		for(int i=0;i<len;i++){
			if(i<len/2){
				a=a*10+(num[i]-'0');
			}else{
				b=b*10+(num[i]-'0');
			}
			c=c*10+(num[i]-'0');
		}
//		printf("%d %d %d\n",a,b,c);
		if(a*b!=0&&c%a==0&&c/a%b==0){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
