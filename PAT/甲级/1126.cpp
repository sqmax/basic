
#include<cstdio>

const int maxn=510;
int degree[maxn];
int G[maxn][maxn];
bool vis[maxn];
int n,m;

void DFS(int v){
	vis[v]=true;
	for(int i=1;i<=n;i++){
		if(G[v][i]==1&&vis[i]==false){
			DFS(i);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a][b]=G[b][a]=1;
		degree[a]++;
		degree[b]++;		
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(degree[i]%2!=0){
			cnt++;
		}
		printf("%d",degree[i]);
		if(i<n) printf(" ");
		else printf("\n");
	}
	DFS(1);
	bool isCon=true;
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			isCon=false;
			break;
		}
	}
	if(isCon&&cnt==0){
		printf("Eulerian\n");
	}else if(isCon&&cnt==2){
		printf("Semi-Eulerian\n");
	}else{
		printf("Non-Eulerian\n");
	} 
	
	return 0;
}
