#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1010;
int G[maxn][maxn],temp[maxn][maxn];
bool vis[maxn];
int n;

void DFS(int s){
	vis[s]=true;
	for(int i=1;i<=n;i++){
		if(vis[i]==false&&G[s][i]==1){
			DFS(i);
		}
	}
}
int main(){
	int m,k;
	scanf("%d%d%d",&n,&m,&k);
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a][b]=G[b][a]=1;
	}
	while(k--){
		int a;
		scanf("%d",&a);
		for(int i=1;i<=n;i++){
			temp[a][i]=G[a][i];
			G[a][i]=G[i][a]=0;
		}
		fill(vis,vis+maxn,false);
		int block=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==false&&i!=a){
				DFS(i);
				block++;
			}
		}
		for(int i=1;i<=n;i++){
			G[a][i]=G[i][a]=temp[a][i];
		}
		printf("%d\n",block-1);
	}
	
}
