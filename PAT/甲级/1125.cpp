#include<cstdio>
#include<algorithm>
using namespace std;


int main(){
	int n;
	scanf("%d",&n);
	int rope[n];
	for(int i=0;i<n;i++){
		scanf("%d",&rope[i]);
	}
	sort(rope,rope+n);
	double sum=rope[0];
	for(int i=1;i<n;i++){
		sum=sum/2.0+rope[i]/2.0;
	}
	printf("%d\n",int(sum));
	
	return 0;
}
