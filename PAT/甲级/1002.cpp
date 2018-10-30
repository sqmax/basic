#include<cstdio>

const int MAXN=1010;
double pol1[MAXN],pol2[MAXN],ans[MAXN];

int main(){
	int a,b,maxExp=0;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		int exp;
		scanf(" %d",&exp);
		scanf(" %lf",&pol1[exp]);
		
		if(exp>maxExp){
			maxExp=exp;
		}
	}
	scanf("%d",&b);
	for(int i=0;i<b;i++){
		int exp;
		scanf(" %d",&exp);
		scanf(" %lf",&pol2[exp]);
		if(exp>maxExp){
			maxExp=exp;	
		}
		
	}
	int cnt=0;
	for(int i=0;i<=maxExp;i++){
		ans[i]=pol1[i]+pol2[i];
		if(ans[i]!=0){
			//printf("i:%d,%.1lf ",i,ans[i]);
			cnt++;
		}
	}
	printf("%d",cnt);
	for(int i=maxExp;i>=0;i--){
		if(ans[i]!=0){
			printf(" %d %.1lf",i,ans[i]);
		}
	}
	return 0;
} 
