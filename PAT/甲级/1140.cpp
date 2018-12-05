#include<cstdio>
#include<cstring>
#include<map> 
using namespace std;

const int maxn=100010;
char a[41][maxn];

int main(){
	int d,n;
	scanf("%s %d",a[0],&n);
	int cnt=0;
	while(cnt<n){
		int k=0;
		for(int i=0;i<strlen(a[cnt]);){
			int temp=1,j;
			for(j=i+1;j<strlen(a[cnt]);j++){
				if(a[cnt][j]==a[cnt][i]){
					temp++;
				}else{
					break;
				}
			}
			a[cnt+1][k++]=a[cnt][i];
			a[cnt+1][k++]=temp+'0';	
			i=j;				
		}
		a[cnt+1][k++]='\0';
		cnt++;
//		printf("%s\n",a[cnt]);
		
	} 
	printf("%s\n",a[n-1]);
	return 0;
}
