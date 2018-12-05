#include<cstdio>
#include<vector>
using namespace std;

const int maxn=210;
int G[maxn][maxn];
int clique[maxn];
bool inVer[maxn];

int main(){
	int nv,ne;
	scanf("%d%d",&nv,&ne);
	for(int i=0;i<ne;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a][b]=G[b][a]=1;
	}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int k,flag=1;
		fill(inVer,inVer+maxn,false);
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&clique[j]);
			inVer[clique[j]]=true;
		}
		for(int p=0;p<k;p++){
			for(int j=p+1;j<k;j++){
				if(G[clique[j]][clique[p]]!=1){
					flag=0;
					break;
				}
			}
			if(flag==0){
				break;
			}
		}
		if(flag==1){
			for(int j=1;j<=nv;j++){
				if(inVer[j]==true) continue;
				int p;
				for(p=0;p<k;p++){
					if(G[j][clique[p]]!=1){
						break;
					}
				}
				if(p==k){
					flag=2;
					break;
				}
			}
		}
		if(flag==0){
			printf("Not a Clique\n");
		}else if(flag==1){
			printf("Yes\n");
		}else{
			printf("Not Maximal\n");
		} 
	}
	return 0;
}
