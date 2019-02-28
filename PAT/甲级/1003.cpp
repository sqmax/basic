#include<cstdio>
#include<algorithm>
#include<iostream> 
using namespace std;

const int maxn=510;
const int INF=0x3fffffff;
int G[maxn][maxn];
int W[maxn];
int d[maxn];
int people[maxn],pathN[maxn];
bool vis[maxn];
int n,m,st,ed;

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	people[s]=W[s];
	pathN[s]=1;
	for(int i=0;i<n;i++){
		int u=-1,Min=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<Min){
				Min=d[j];
				u=j;
			}
		}
		if(u==-1) break;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];	
					people[v]=people[u]+W[v];
					pathN[v]=pathN[u];
				}else if(d[u]+G[u][v]==d[v]){
					if(people[v]<people[u]+W[v]){
						people[v]=people[u]+W[v];
					}
					pathN[v]+=pathN[u];
				}
				
			}
		}
	}
}
int main(){
	cin>>n>>m>>st>>ed;
	for(int i=0;i<n;i++){
		cin>>W[i];
	}
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<m;i++){
		int a,b,dis;
		cin>>a>>b>>dis;
		G[a][b]=G[b][a]=dis;
	}
	Dijkstra(st);
	printf("%d %d\n",pathN[ed],people[ed]);
	
	return 0;
}
