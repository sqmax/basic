#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

const int maxn=100010;
struct Node{
	int key,level;
	vector<int> childs;
}node[maxn];
int maxL=-1,cnt=0;
void levelOrder(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int front=q.front();
		q.pop();
		if(node[front].level>maxL){
			maxL=node[front].level;
			cnt=1;
		}else if(node[front].level==maxL){
			cnt++;
		}
		for(int i=0;i<node[front].childs.size();i++){
			int child=node[front].childs[i];
			node[child].level=node[front].level+1;
			q.push(child);
		}
	}
}
int main(){
	int n;
	double p,r;
	scanf("%d %lf %lf",&n,&p,&r);
	int R; 
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(a!=-1){
			node[a].childs.push_back(i);	
		}else{
			R=i;
		}
	}
	
	levelOrder(R);

	printf("%.02f %d\n",p*pow((1+r/100),maxL),cnt);
	
	return 0;
}
