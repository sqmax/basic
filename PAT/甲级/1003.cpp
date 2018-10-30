#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXV=510;
const int INF=10000000;

int n,m,c1,c2;
int d[MAXV],G[MAXV][MAXV];
bool vis[MAXV]={false};
int person[MAXV];
int num[MAXV]={0},w[MAXV]={0};

void Dijkstra(){
	fill(d,d+MAXV,INF);
	d[c1]=0,w[c1]=person[c1],num[c1]=1;
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
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					w[v]=w[u]+person[v];
					num[v]=num[u];
				}else if(d[u]+G[u][v]==d[v]){
					if(w[u]+person[v]>w[v]){
						w[v]=w[u]+person[v];
					}
					num[v]+=num[u];
				}
				
			}
		}
	}
}
int main(){
	
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	for(int i=0;i<n;i++){
		scanf("%d",&person[i]);
	}
	fill(G[0],G[0]+MAXV*MAXV,INF);
	int s,e,d;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&s,&e,&d);
		G[s][e]=G[e][s]=d;
	}
	Dijkstra();
	
	printf("%d %d\n",num[c2],w[c2]);
	
	return 0;
}
