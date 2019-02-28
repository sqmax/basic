#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=510;
const int INF=0x3fffffff;
int G[maxn][maxn];
int T[maxn][maxn],D[maxn][maxn];
int t[maxn],d[maxn];
bool vis[maxn];
vector<int> pre1[maxn],pre2[maxn];
int n,m;
int st,ed;
void DijkstraOnDis(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,Min=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<Min){
				u=j;
				Min=d[j];
			} 
		}
		if(u==-1) return;
		vis[u]=true;
//		printf("%d\n",u); 
		for(int v=0;v<n;v++){
			if(vis[v]==false&&D[u][v]!=INF){
				if(d[u]+D[u][v]<d[v]){
					d[v]=d[u]+D[u][v];
					pre1[v].clear();
					pre1[v].push_back(u);
				}else if(d[u]+D[u][v]==d[v]){
					pre1[v].push_back(u);
				}
			}
		}
	}
}
int shortest=INF;
vector<int> path,ans1;
void DFSOnDis(int e){
	path.push_back(e);
	if(e==st){
		int totTime=0;
		for(int i=path.size()-1;i>0;i--){
			totTime+=T[path[i]][path[i-1]];
		}
		if(totTime<shortest){
			shortest=totTime;
			ans1=path;
		}
		path.pop_back();
		return;
	}
	for(int i=0;i<pre1[e].size();i++){
		int pre=pre1[e][i];
		DFSOnDis(pre);
	}
	path.pop_back();
}
void DijkstraOnTime(int s){
	fill(t,t+maxn,INF);
	fill(vis,vis+maxn,false);
	t[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,Min=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&t[j]<Min){
				u=j;
				Min=t[j];
			} 
		}
		if(u==-1) return;
		vis[u]=true;
//		printf("%d\n",u); 
		for(int v=0;v<n;v++){
			if(vis[v]==false&&T[u][v]!=INF){
				if(t[u]+T[u][v]<t[v]){
					t[v]=t[u]+T[u][v];
					pre2[v].clear();
					pre2[v].push_back(u);
				}else if(t[u]+T[u][v]==t[v]){
					pre2[v].push_back(u);
				}
			}
		}
	}
}
int fewest=INF;
vector<int> ans2;
void DFSOnTime(int e){
	path.push_back(e);
	if(e==st){
		if(path.size()<fewest){
			fewest=path.size();
			ans2=path;
		}
		path.pop_back();
		return;
	}
	for(int i=0;i<pre2[e].size();i++){
		int pre=pre2[e][i];
		DFSOnTime(pre);
	}
	path.pop_back();
}
int main(){
	cin>>n>>m;
	fill(T[0],T[0]+maxn*maxn,INF);
	fill(D[0],D[0]+maxn*maxn,INF);
	for(int i=0;i<m;i++){
		int a,b,ow,len,time;
		cin>>a>>b>>ow>>len>>time;
		T[a][b]=time;
		D[a][b]=len;
		if(ow==0){
			T[b][a]=time;
			D[b][a]=len;
		}
	}	
	cin>>st>>ed;
	DijkstraOnDis(st);	
	DFSOnDis(ed);
	
	DijkstraOnTime(st);
	DFSOnTime(ed);
	
	if(ans1==ans2){
		printf("Distance = %d; Time = %d: %d",d[ed],t[ed],st);
		for(int i=ans1.size()-2;i>=0;i--){
			printf(" -> %d",ans1[i]);
		}
	}else{
		printf("Distance = %d: %d",d[ed],st);
		for(int i=ans1.size()-2;i>=0;i--){
			printf(" -> %d",ans1[i]);
		}
		printf("\n");
		printf("Time = %d: %d",t[ed],st);
		for(int i=ans2.size()-2;i>=0;i--){
			printf(" -> %d",ans2[i]);
		}
	}
	
	return 0;
}
