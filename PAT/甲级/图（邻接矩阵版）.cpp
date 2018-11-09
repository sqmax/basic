#include<cstdio>

const int MAXV=1010;
const int INF=0x70000000;

int n,G[MAXV][MAXV];
bool vis[MAXV]={false};

void DFS(int u,int depth){
	vis[u]=true;
	for(int v=0;v<n;v++){
		if(vis[v]==false&&G[u][v]!=INF){
			DFS(v,depth+1);
		}
	}
} 
void DFSTrave(){
	for(int u=0;u<n;u++){
		if(vis[u]==false){
			DFS(u,1);
		}
	}
}

int main(){
	
	return 0;
}
