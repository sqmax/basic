#include<cstdio>
#include<cstring>

const int maxn=1010;
char a[maxn],b;
char res[maxn];

int main(){
	scanf("%s %d",a,&b);
	int left=0,cnt=0;
	
	for(int i=0;i<strlen(a);i++){
		int t=a[i]-'0'+left*10;
		res[cnt++]=t/b+'0';	
		left=t%b;		
	}	
	char* deleteHead0=res;
	while(*deleteHead0=='0'&&strlen(deleteHead0)>1){
		deleteHead0++;
	}
	printf("%s %d\n",deleteHead0,left);
	
	return 0;
}
