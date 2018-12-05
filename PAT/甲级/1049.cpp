#include<cstdio>
#include<cstring>

int contains1(int x){
	int cnt=0;
	while(x){
		int a=x%10;
		if(a==1){
			cnt++;
		}
		x/=10;
	}
	return cnt;
}
int main(){
	int n;
	scanf("%d",&n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=contains1(i);
	}
	printf("%d\n",cnt);
	
	return 0;
} 
