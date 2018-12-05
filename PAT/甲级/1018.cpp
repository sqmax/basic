#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

const int maxn=510;
const int INF=1000000;
int G[maxn][maxn];
int d[maxn];
vector<int> pre[maxn];
int bike[maxn];
bool vis[maxn];
int C,N,S,M;

void Dijkstra(){
	fill(d,d+maxn,INF);
	d[0]=0;
	for(int i=0;i<=N;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<=N;j++){
			if(vis[j]==false&&d[j]<MIN){
				MIN=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<=N;v++){
			if(vis[v]==false){	
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+G[u][v]==d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}	
} 
vector<int> temp,ans;
int minNeed=INF;
void DFS(int des){
	if(des==0){
		temp.push_back(des);
		int totBike=0;
		for(int i=0;i<temp.size();i++){
			totBike+=bike[temp[i]];
		}
		int need=(temp.size()-1)*C/2;
		if(abs(need-totBike)<minNeed){
			minNeed=need-totBike;
			ans=temp;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(des);
	for(int i=0;i<pre[des].size();i++){
		DFS(pre[des][i]);
	}
	temp.pop_back();
}
int main(){
	scanf("%d%d%d%d",&C,&N,&S,&M);
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=1;i<=N;i++){
		scanf("%d",&bike[i]);
	}
	for(int i=0;i<M;i++){
		int a,b,t;
		scanf("%d%d%d",&a,&b,&t);
		G[a][b]=G[b][a]=t;
	}
	Dijkstra();
	
	DFS(S);
	
	if(minNeed<0) printf("0 ");
	else printf("%d ",minNeed);
	for(int i=ans.size()-1;i>0;i--){
		printf("%d->",ans[i]);
	}
	printf("%d ",S);
	
	if(minNeed<0) printf("%d\n",-minNeed);
	else printf("0\n");
	return 0;
}
