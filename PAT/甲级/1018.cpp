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
int W[maxn];
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
int minNeed=INF,minRemain=INF;
void DFS(int des){
	temp.push_back(des);
	if(des==0){
		int need=0,remain=0;
		for(int i=temp.size()-1;i>=0;i--){
			int id=temp[i];
			if(W[id]>0){
				remain+=W[id];
			}else{
				if(remain>abs(W[id])){
					remain-=abs(W[id]);
				}else{
					need+=abs(W[id])-remain;
					remain=0;
				}
			}
		}
		if(need<minNeed){
			minNeed=need;
			minRemain=remain;
			ans=temp;
		}else if(need==minNeed&&remain<minRemain){
			minRemain=remain;
			ans=temp;
		}
	}
	for(int i=0;i<pre[des].size();i++){
		DFS(pre[des][i]);
	}
	temp.pop_back();
}
int main(){
	scanf("%d%d%d%d",&C,&N,&S,&M);
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=1;i<=N;i++){
		int x;
		scanf("%d",&x);
		W[i]=x-C/2;
	}
	for(int i=0;i<M;i++){
		int a,b,t;
		scanf("%d%d%d",&a,&b,&t);
		G[a][b]=G[b][a]=t;
	}
	Dijkstra();
	
	DFS(S);
	
	printf("%d ",minNeed);
	for(int i=ans.size()-1;i>=0;i--){
		printf("%d",ans[i]);
		if(i>0) printf("->");
	}
	printf(" %d",minRemain);
	
	return 0;
}
