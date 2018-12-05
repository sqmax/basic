#include<cstdio>
#include<cstring>

const int maxn=1010;
char str[maxn],a[maxn];
int cnt[160]={0};
int provided[160],wanted[160];

int main(){
	scanf("%s",str);
	scanf("%s",a);
	for(int i=0;i<strlen(str);i++){
		provided[str[i]]++;
	}
	
	for(int i=0;i<strlen(a);i++){
		wanted[a[i]]++;
	}
	int more=0,less=0;
	bool flg=false;
	for(int i='0';i<='z';i++){
		if(provided[i]>=wanted[i]){
			more+=provided[i]-wanted[i];
		}else{
			less+=wanted[i]-provided[i];
			flg=true;
		}
	}

	
	if(flg==true){
		printf("NO %d\n",less);
	}else{
		printf("Yes %d\n",more);
	}
	
	return 0;
} 
