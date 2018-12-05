//不知道错哪里了 
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100010;
int dis[maxn];

int main(){
	int n;
	scanf("%d",&n);
	int Max=0;
	for(int i=0;i<n;i++){
		scanf("%d",&dis[i]);
		if(dis[i]>Max){
			Max=dis[i];
		}
	}
	sort(dis,dis+n);
	int ans=0;
	for(int i=0;i<=Max;i++){
		int k=upper_bound(dis,dis+n,i)-dis;
		if(n-k==i){
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
	
	return 0;
}
