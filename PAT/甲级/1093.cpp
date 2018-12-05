#include<cstdio>
#include<cstring>

const int maxn=100010;
char str[maxn];
int leftP[maxn],rightT[maxn];

int main(){
	scanf("%s",str);
	int len=strlen(str);
	if(str[0]=='P') leftP[0]=1;
	for(int i=1;i<len;i++){
		if(str[i]=='P'){
			leftP[i]=leftP[i-1]+1;
		}else{
			leftP[i]=leftP[i-1];
		}
	}
	if(str[len-1]=='T') rightT[len-1]=1;	
	for(int i=len-2;i>=0;i--){
		if(str[i]=='T'){
			rightT[i]=rightT[i+1]+1;
		}else{
			rightT[i]=rightT[i+1];
		}
	}
	int sum=0;
	for(int i=0;i<len;i++){
		if(str[i]=='A'){
			sum=(sum+leftP[i]*rightT[i])%1000000007;
		}
	}
	printf("%d\n",sum);
	
	return 0;
}
