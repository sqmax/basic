#include<cstdio>

const int maxn=1010;
int G[maxn][maxn];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a][b]=1;
		G[b][a]=-1;
	}
	int k;
	scanf("%d",&k);
	int ans[n],cnt=0;
	for(int i=0;i<k;i++){
		int a[n];
		for(int j=0;j<n;j++){
			scanf("%d",&a[j]);
		}
		bool flag=false;
		for(int p=0;p<n;p++){
			for(int l=p+1;l<n;l++){
				if(G[a[p]][a[l]]==-1){
					flag=true;
					ans[cnt++]=i;
					break;
				}
			}
			if(flag==true) break;
		}	
	}
	for(int i=0;i<cnt;i++){
		printf("%d",ans[i]);
		if(i<cnt-1) printf(" ");
	}
	
	return 0;
}
