#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXV=1010;
const int INF=0x3fffffff;
int G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV]={false};
int weight[MAXV];
int w[MAXV];
int num[MAXV];
int n,m,C1,C2;

void Dijkstra(int s){
	fill(d,d+MAXV,INF);
	d[s]=0;
	w[s]=weight[s];
	num[s]=1;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1){
			return;
		}
//		printf("%d ",u);
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]<INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					w[v]=w[u]+weight[v];
					num[v]=num[u];	
				}else if(d[u]+G[u][v]==d[v]){
					d[v]=d[u]+G[u][v];
					num[v]=num[u]+1;
					if(w[v]<w[u]+weight[v]){
						w[v]=w[u]+weight[v];
					}
				}
				
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&C1,&C2);
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);
	}
	fill(G[0],G[0]+MAXV*MAXV,INF);
	for(int i=0;i<m;i++){
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		G[a][b]=G[b][a]=w;
	}
	
	Dijkstra(C1);
	
	printf("%d %d\n",num[C2],w[C2]);
	
	return 0;
}
