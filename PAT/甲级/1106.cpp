#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

const int maxn=100010;
struct Node{
	int level;
	vector<int> childs;
}node[maxn];
int minDep=10000,cnt=0;
void DFS(int root,int depth){
	if(node[root].childs.size()==0){
		if(depth<minDep){
			minDep=depth;
			cnt=1;
		}else if(depth==minDep){
			cnt++;
		}
//		printf("deP:%d\n",depth);
	}
	for(int i=0;i<node[root].childs.size();i++){
		DFS(node[root].childs[i],depth+1);
	}
}
int main(){
	int n;
	double p,r;
	scanf("%d %lf %lf",&n,&p,&r);
	
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int a;
			scanf("%d",&a);
			node[i].childs.push_back(a);
		}
	}
	DFS(0,0);
	printf("%.4lf %d\n",p*pow(1+r/100,minDep),cnt);
	
	return 0;
}
