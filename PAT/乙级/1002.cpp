#include<cstdio>
#include<cstring>


const int MAXN=110;
char n[MAXN];
char res[11][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","shi"};

int main(){
	
	scanf("%s",n);
	int sum=0;
	for(int i=0;i<strlen(n);i++){
		sum=sum+n[i]-'0';
	}	

	int a=1,temp=sum;
	while(temp>=10){
		temp/=10;
		a*=10;
	}

	bool flag=false;
	do{
		temp=sum/a;
		sum%=a;
		a/=10;
		if(flag==false){
			flag=true;
		}else{
			printf(" ");
		}
		printf("%s",res[temp]);

	}while(a>0);
	
	return 0;
} 
