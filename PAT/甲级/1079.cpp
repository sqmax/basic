#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

const int maxn=100010;
struct Node{
	int w;
	vector<int> childs;
}node[maxn];
int n;
double p,r;

double ans=0;
void DFS(int root,int height){
	if(node[root].childs.size()==0){
		ans+=p*pow(1+r/100,height)*node[root].w;
		return;
	}
	for(int i=0;i<node[root].childs.size();i++){
		DFS(node[root].childs[i],height+1);
	}
}
int main(){

	scanf("%d %lf %lf",&n,&p,&r);
	
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int ch;
			scanf("%d",&ch);
			node[i].childs.push_back(ch);
		}
		if(k==0){
			scanf("%d",&node[i].w);
		}
	}
	DFS(0,0);
	
	printf("%.1f\n",ans);
	
	return 0;
}


