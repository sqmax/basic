#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

const int MAXV=3010;
const int INF=0x3fffffff;
int G[MAXV][MAXV];
int gender[MAXV];
bool vis[MAXV];
int n,m;
map<int,int> idToN;
map<int,int> nToId;

void contact(int a,int b,int &cnt,vector<int> path[]){
	for(int i=0;i<MAXV;i++){
		if(i!=a&&i!=b&&G[a][i]==1&&gender[i]==gender[a]){
			for(int j=0;j<MAXV;j++){
				if(j!=i&&j!=a&&j!=b&&G[j][i]==1&&G[j][b]==1&&gender[j]==gender[b]){					
					path[cnt].push_back(i);
					path[cnt].push_back(j);
					cnt++;
//					printf("%04d %04d\n",i,j);	
				}
			}
		}
	}
} 
int main(){
	scanf("%d%d",&n,&m);
	fill(G[0],G[0]+MAXV*MAXV,INF);
	int a,b;
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		if(a>0){
			gender[a]=1;
		}else{
			a=-a;
		}
		if(b>0){
			gender[b]=1;
		}else{
			b=-b;
		}
		G[a][b]=G[b][a]=1;

	}	
	int k;
	scanf("%d",&k);
	
	for(int i=0;i<k;i++){
		scanf("%d%d",&a,&b);
		vector<int> path[m];
		int cnt=0;
		if(a<0){
			a=-a;
		}
		if(b<0){
			b=-b;
		}
		contact(a,b,cnt,path);
		printf("%d\n",cnt);
		if(cnt>0){
			for(int i=0;i<cnt;i++){
				printf("%04d %04d\n",path[i][0],path[i][1]);
			}
		}
		
	}
}
