#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

const int maxn=10010;
const int INF=0x3fffffff;
vector<int> G[maxn];
int dist[maxn];
bool vis[maxn];
int line[maxn][maxn];
vector<int> pre[maxn],tmpPath,path,path2;
int src,dest,minTrans;
set<int> stations;

void init(){
	minTrans=INF;
	fill(vis,vis+maxn,false);
	fill(dist,dist+maxn,INF);
	path.clear();
	tmpPath.clear();
	for(int i=0;i<maxn;i++){
		pre[i].clear();
	}
}
void Dijkstra(){
	dist[src]=0;
	for(int i=0;i<stations.size();i++){
		int	u=-1,MIN=INF;
		for(set<int>::iterator it=stations.begin();it!=stations.end();it++){
			int nextV=*it;
			if(vis[nextV]==false&&dist[nextV]<MIN){
				u=nextV;
				MIN=dist[nextV];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int i=0;i<G[u].size();i++){
			int nextV=G[u][i];
			if(vis[nextV]==false){
				if(dist[u]+1<dist[nextV]){
					dist[nextV]=dist[u]+1;
					pre[nextV].clear();
					pre[nextV].push_back(u);
				}else if(dist[u]+1==dist[nextV]){
					pre[nextV].push_back(u);
				}
			}
		}
	} 
}
void calCost(){
	int tmpTrans=-1,lineId=0;
	for(int i=tmpPath.size()-1;i>0;i--){
		int v=tmpPath[i];
		int nextV=tmpPath[i-1];
		if(line[v][nextV]!=lineId){
			tmpTrans++;
		}
		lineId=line[v][nextV];
	}
	if(tmpTrans<minTrans){
		minTrans=tmpTrans;
		path=tmpPath;
	} 
}
void DFS(int v){
	if(v==src){
		tmpPath.push_back(v);
		calCost();
		tmpPath.pop_back();
		return;
	}
	tmpPath.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		DFS(pre[v][i]);
	}
	tmpPath.pop_back();
}
void getRoute(){
	reverse(path.begin(),path.end());
	int v1=path[0],v2=path[1];
	int i=0,len=path.size();
	int lineId=line[v1][v2];
	
	printf("Take Line#%d from ",lineId);
	printf("%04d to ",v1);
	for(int j=0;j<minTrans;j++){
		while(i<len-1){
			if(lineId!=line[v1][v2]){
				break;
			}
			v1=path[i];
			v2=path[i+1];
			i++;
		}
		printf("%04d.\n",v1);
		lineId=line[v1][v2];
		printf("Take Line#%d from ",lineId);
		printf("%04d to ",v1);
	}
	v2=path[len-1];
	printf("%04d.\n",v2);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int m,v1,v2;
		scanf("%d %d",&m,&v1);
		for(int j=1;j<m;j++){
			scanf("%d",&v2);
			G[v1].push_back(v2);
			G[v2].push_back(v1);
			line[v1][v2]=line[v2][v1]=i;
			stations.insert(v1);
			stations.insert(v2);
			v1=v2;
		}
	}
	int k;
	scanf("%d",&k);
	while(k--){
		init();
		scanf("%d%d",&src,&dest);
		Dijkstra();
		DFS(dest);
		printf("%d\n",dist[dest]);
		getRoute();
	}
	
	return 0;
}
