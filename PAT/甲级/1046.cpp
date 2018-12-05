#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100010;
int dis[maxn];

int main(){
	int n;
	scanf("%d",&n);
	int tot=0;
	int a;
	for(int i=2;i<=n;i++){
		scanf("%d",&a);
		dis[i]=dis[i-1]+a;
	}
	scanf("%d",&a);
	tot=dis[n]+a;
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);
		int dis1=dis[b]-dis[a];
		
		printf("%d\n",min(dis1,tot-dis1));
	}
	
	return 0;
}
