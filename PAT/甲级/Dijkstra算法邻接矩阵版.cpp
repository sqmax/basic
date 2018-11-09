#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXV=1010;
const int INF=0x3fffffff;
struct Node{
	int v,dis;
}; 
int n,m,s;
vector<Node> adj[MAXV];
int d[MAXV];
bool vis[MAXV]={false}; 

void Dijkstra(int s){
	fill(d,d+MAXV,INF);
	d[s]=0;
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
		vis[u]=true;
		for(int j=0;j<adj[u].size();j++){
			int v=adj[u][j].v;
			if(vis[v]==false&&d[u]+adj[u][j].dis<d[v]){
				d[v]=d[u]+adj[u][j].dis;
			}
		}
	}
}
int main(){
	
	return 0;
}

