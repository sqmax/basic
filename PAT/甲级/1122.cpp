#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1010;
int G[maxn][maxn];
int N,M;
bool isHamCyc(int v[],int n){
	bool ans=true;
	bool vis[N+1];
	fill(vis,vis+N+1,false);
	if(n!=N+1) ans=false;
	else if(v[0]!=v[n-1]) ans=false;
	else{
		for(int i=0;i<n;i++){
			vis[v[i]]=true;
		}
		for(int i=1;i<=N;i++){
			if(vis[i]==false){
				ans=false;
				break;
			}
		}
		for(int i=0;i<n-1;i++){
			if(G[v[i]][v[i+1]]!=1){
				ans=false;
				break;
			}
		}
	}
	return ans;
}
int main(){
	
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a][b]=G[b][a]=1;
	}
	int k;
	scanf("%d",&k);
	while(k--){
		int nv;
		scanf("%d",&nv);
		int v[nv];
		for(int i=0;i<nv;i++){
			scanf("%d",&v[i]);
		}
		bool ans=isHamCyc(v,nv);
		ans?printf("YES\n"):printf("NO\n");
	}
	
	return 0;
}
