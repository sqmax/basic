#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100010;
long long a[maxn]; 

int main(){
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);		
	}
	sort(a,a+n);
	int maxL=0;
	for(int i=0;i<n;i++){
		long long np=a[i]*p;
		int pos=upper_bound(a,a+n,np)-a;
		if(pos-i>maxL){
			maxL=pos-i;
		}
		if(i>maxL) break;
	}
	printf("%d\n",maxL);
	
	return 0;
}
