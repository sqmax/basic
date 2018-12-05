#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

const int maxn=1010;
const int INF=1000000;

int G[maxn][maxn]={0};
int length[maxn][maxn];
int time[maxn][maxn];
int d[maxn],t[maxn];
bool vis[maxn];
int pre[maxn];
int S,D;
int n,m;

void DijkstraForDis(int s){
	fill(d,d+maxn,INF);
	fill(t,t+maxn,INF);
	d[s]=0;
	t[s]=0;
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
//		printf("%d\n",u);
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]==1){
				if(d[u]+length[u][v]<d[v]){
					d[v]=d[u]+length[u][v];
					pre[v]=u;
//					pre[v].clear();
//					pre[v].push_back(u);
				}
				else if(d[u]+length[u][v]==d[v]){
					if(t[u]+time[u][v]<t[v]){
						t[v]=t[u]+time[u][v];
						pre[v]=u;
					}
				}
			}
		}
	}
}
vector<int> pre2[maxn];
void DijkstraForTime(int s){
	fill(t,t+maxn,INF);
	t[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&t[j]<MIN){
				u=j;
				MIN=t[j];
			}
		}
		if(u==-1){
			return;
		}
		vis[u]=true;
//		printf("%d\n",u);
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]==1){
				if(t[u]+time[u][v]<t[v]){
					t[v]=t[u]+time[u][v];
					pre2[v].clear();
					pre2[v].push_back(u);
				}
				else if(t[u]+time[u][v]==t[v]){
					pre2[v].push_back(u);
				}
			}
		}
	}
}
vector<int> path1;
void DFS1(int d){
	if(d==S){
		path1.push_back(d);
		return;
	}
	DFS1(pre[d]);
	path1.push_back(d);
//	printf(" -> %d",d);
}
vector<int> path2,tmp;
int minInter=INF; 
void DFS2(int d){
	if(d==S){
		tmp.push_back(d);
		if(tmp.size()<minInter){
			minInter=tmp.size();
			path2=tmp;
		}
		tmp.pop_back();
		
		return;
	}
	tmp.push_back(d);
	for(int i=0;i<pre2[d].size();i++){
		DFS2(pre2[d][i]);
	}
	tmp.pop_back();
}

int main(){

	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int v1,v2,ow,l,t;
		scanf("%d%d%d%d%d",&v1,&v2,&ow,&l,&t);
		G[v1][v2]=1;
		if(ow==0){
			G[v2][v1]=1;
		}
		length[v1][v2]=length[v2][v1]=l;
		time[v1][v2]=time[v2][v1]=t;
	}
	scanf("%d%d",&S,&D);
	DijkstraForDis(S);
	DFS1(D);
	
	fill(vis,vis+maxn,false);
	DijkstraForTime(S);
	DFS2(D);
	reverse(path2.begin(),path2.end());
	if(path1==path2){
		printf("Distance = %d; Time = %d: %d",d[D],t[D],S);
		for(int i=1;i<path1.size();i++){
			printf(" -> %d",path1[i]);
		}
	}else{
		printf("Distance = %d: %d",d[D],S);
		for(int i=1;i<path1.size();i++){
			printf(" -> %d",path1[i]);
		}
		printf("\n");
		printf("Time = %d: %d",t[D],S);
		for(int i=1;i<path2.size();i++){
			printf(" -> %d",path2[i]);
		}
		printf("\n");
	}	
} 
