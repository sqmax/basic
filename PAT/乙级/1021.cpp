#include<cstdio>

int cnt[10];

int main(){
	char* n=new char[1000];
	scanf("%s",n);
	char* t=n;
	while(*n!='\0'){
		cnt[*n-'0']++;
		n++;
	}
	for(int i=0;i<10;i++){
		if(cnt[i]){
			printf("%d:%d\n",i,cnt[i]);
		}
	}
//	delete t;
	return 0;
		
} 
