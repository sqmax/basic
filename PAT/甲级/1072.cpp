#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;

const int INF=0x3fffffff;
const int maxn=1020;
int G[maxn][maxn];
int d[maxn];
bool vis[maxn];
int n,m,k,ds;

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	fill(vis,vis+maxn,false);
	d[s]=0;
	for(int i=1;i<=n+m;i++){
		int u=-1,MIN=INF;
		for(int j=1;j<=n+m;j++){
			if(vis[j]==false&&d[j]<MIN){
				MIN=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=1;v<=n+m;v++){
			if(vis[v]==false&&d[u]+G[u][v]<d[v]){
				d[v]=d[u]+G[u][v];
			}
		}
	}
}
bool checkServiceRange(int &tot,int &minDis){
	for(int i=1;i<=n;i++){
		if(d[i]>ds){
			return false;
		}
		if(d[i]<minDis){
			minDis=d[i];
		}
		tot+=d[i];
	}
	return true;
}
int getId(char a[]){
	int rnt=0;
	if(a[0]=='G'){
		rnt=a[1]-'0'+4;
	}else{
		rnt=a[0]-'0';
	}
	return rnt;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<k;i++){
		char p1[5],p2[10];
		int dist;
		scanf("%s %s %d",p1,p2,&dist);
		int g1,g2;
		g1=getId(p1);
		g2=getId(p2);
		G[g1][g2]=G[g2][g1]=dist;
	}
	
	int bestDis=-1,minTot=INF,station;
	for(int sta=n+1;sta<=n+m;sta++){		
		Dijkstra(sta);
//		printf("%d-------\n",*it-4);
//		for(int i=1;i<=n;i++){
//			printf("%d ",d[i]);
//		}
//		printf("\n");
		int minDis=INF,tot=0;
		if(checkServiceRange(tot,minDis)){
			if(minDis>bestDis){
				bestDis=minDis;
				minTot=tot;
				station=sta;
			}else if(minDis==bestDis){
				if(tot<minTot){
					minTot=tot;
					station=sta;	
				}
			}
//			printf("%d %d %d\n",bestDis,minTot,*it-4);
		}	
	}
	if(bestDis==-1){
		printf("No Solution\n");
	}else{
		printf("G%d\n",station-4);
		printf("%.01f %.1f\n",bestDis*1.0,minTot*1.0/n+0.05);
	}
	
	return 0;
}
