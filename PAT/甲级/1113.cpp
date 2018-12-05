#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100010;
int a[maxn];

int main(){
	int n;
	scanf("%d",&n);
	int sum=0,A1=0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n/2;i++){
		A1+=a[i];
	}
	if(n%2){
		printf("1");
	}else{
		printf("0");
	}
	printf(" %d\n",sum-A1-A1);
	return 0;
} 
