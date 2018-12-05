#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXV=1010;
const int INF=0x3fffffff;
int G[MAXV][MAXV];
int Cost[MAXV][MAXV];
int d[MAXV],c[MAXV];
int pre[MAXV];
bool vis[MAXV];
int n,m,S,D;

void Dijkstra(int s){
	fill(d,d+MAXV,INF);
	fill(c,c+MAXV,INF);
	d[s]=0;
	c[s]=0;
	for(int i=0;i<n;i++){
		pre[i]=i;
	}
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<MIN){
				MIN=d[j];
				u=j;
			}
		}
		if(u==-1){
			return;
		}
		vis[u]=true;
//		printf("%d\n",u);
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]<INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					c[v]=c[u]+Cost[u][v];
					pre[v]=u;
				}else if(d[u]+G[u][v]==d[v]){
					if(c[u]+Cost[u][v]<c[v]){
						c[v]=c[u]+Cost[u][v];
						pre[v]=u;
					}			
				}
			} 
		}
	}
}
void DFS(int idx){
	if(idx==S){
		printf("%d ",idx);
		return;
	}
	DFS(pre[idx]);
	printf("%d ",idx);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&S,&D);
	fill(G[0],G[0]+MAXV*MAXV,INF);
	int c1,c2,dis,cost;
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&c1,&c2,&dis,&cost);
		G[c1][c2]=G[c2][c1]=dis;
		Cost[c1][c2]=Cost[c2][c1]=cost;
	}
	Dijkstra(S);
	DFS(D);
	printf("%d %d\n",d[D],c[D]);
	
	return 0;
}
