#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1010;
const int INF=0x3fffffff;
int G[maxn][maxn];
int C[maxn][maxn];
int d[maxn];
int c[maxn];
int pre[maxn];
bool vis[maxn];
int N,M,S,D;

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	fill(c,c+maxn,INF);
	d[s]=0;
	c[s]=0;
	for(int i=0;i<N;i++){
		pre[i]=i;
	}
	for(int i=0;i<N;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<N;j++){
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1){
			return;
		}
		vis[u]=true;
		for(int v=0;v<N;v++){
			if(vis[v]==false&&G[u][v]<INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					c[v]=c[u]+C[u][v];
					pre[v]=u;				
				}else if(d[u]+G[u][v]==d[v]){
					if(c[u]+C[u][v]<c[v]){
						c[v]=c[u]+C[u][v];
						pre[v]=u;
					}
				}
			}
		}
	}
}
void DFS(int d){
	if(d==S){
		printf("%d ",d);
		return;
	}
	DFS(pre[d]);
	printf("%d ",d);
}
int main(){
	scanf("%d%d%d%d",&N,&M,&S,&D);
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<M;i++){
		int c1,c2,dis,cost;
		scanf("%d%d%d%d",&c1,&c2,&dis,&cost);
		G[c1][c2]=G[c2][c1]=dis;
		C[c1][c2]=C[c2][c1]=cost;
	}
	Dijkstra(S);
	
	DFS(D);
	printf("%d %d",d[D],c[D]);
	
	return 0;
	
} 
