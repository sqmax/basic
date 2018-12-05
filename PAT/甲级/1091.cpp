#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

const int maxm=1500;
const int maxn=1300;
struct Node{
	int x,y;
};
int G[maxm][maxn];
bool inq[maxm][maxn];
int X[8]={0,0,1,-1,1,1,-1,-1};
int Y[8]={1,-1,0,0,1,-1,1,-1};
int m,n,l,t;

bool judge(int x,int y){
	if(x>=m||x<0||y>=n||y<0) return false;
	if(G[x][y]==0||inq[x][y]==true) return false;
	return true;
} 
int BFS(int x,int y){
	queue<Node> q;
	Node node;
	node.x=x,node.y=y;
	q.push(node);
	inq[x][y]=true;
	int tot=0;
	while(!q.empty()){
		Node front=q.front();
		q.pop();
		tot++;
		for(int i=0;i<8;i++){
			int newX=front.x+X[i];
			int newY=front.y+Y[i];
			
			if(judge(newX,newY)){
				Node node;
				node.x=newX;
				node.y=newY;
				q.push(node);
				inq[newX][newY]=true;
			}
		}
	}
	if(tot>=t){
		return tot;
	}else{
		return 0;
	}
}
int main(){
	scanf("%d%d%d%d",&m,&n,&l,&t);
	int total=0;
	while(l--){
		fill(inq[0],inq[0]+maxm*maxn,false);
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&G[i][j]);
			}
		}	
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(inq[i][j]==false&&G[i][j]==1){
					total+=BFS(i,j);	
				}
				
			}
		}
	}
	
	printf("%d\n",total);
	
	return 0;
} 
