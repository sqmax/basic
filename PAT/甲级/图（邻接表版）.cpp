#include<cstdio>
#include<vector>
using namespace std;

const int MAXV=1010;
const int INF=0x70000000;

vector<int> adj[MAXV];
int n;
bool vis[MAXV]={false};

void DFS(int u,int depth){
	vis[u]=true;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(vis[v]==false){
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
