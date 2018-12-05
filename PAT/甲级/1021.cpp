#include<cstdio>
#include<vector>
#include<set>
using namespace std;

const int maxn=10010;
int G[maxn][maxn];
int n;
bool vis[maxn];
set<int> ans;

int maxH=0;
void DFS(int idx,int height){
	vis[idx]=true;
	if(height>maxH){
		maxH=height;
		ans.clear();
		ans.insert(idx);
	}else if(height==maxH){
		ans.insert(idx);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==false&&G[idx][i]==1){
			DFS(i,height+1);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a][b]=G[b][a]=1;
	}
	int k=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			DFS(i,0);
			k++;
		}
	}
	if(k>1){
		printf("Error: %d components\n",k);
	}else{
		for(int i=1;i<=n;i++){
			fill(vis,vis+maxn,false);
			DFS(i,0);
		}
		for(set<int>::iterator it=ans.begin();it!=ans.end();it++){
			printf("%d\n",*it);
		} 
	}
	
}
