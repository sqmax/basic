//思路：n个节点的图有n-1条边，如果图是连通的话，那该图一定是一颗树
//判断是否连通，可用并查集，也可像我这样DFS
//是树的话选任一个结点为树根，遍历的，可得到部分最深的根
//然后以从部分最深的根中选取1个为树根，再次深度优先遍历，可再次得到部分最深的根
//两次的并集即为所有最深的根 

//我开始是判断图连通后，对所有节点进行深度优先遍历，但这样会超时。 
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
 
const int maxn=10010;
int G[maxn][maxn],n;
bool vis[maxn];
int maxH=0;
set<int> ans; 
void DFS(int idx,int height){
	if(vis[idx]) return;
	if(height>maxH){
		ans.clear();
		maxH=height;
		ans.insert(idx);
	}else if(height==maxH){
		ans.insert(idx);
	}
	vis[idx]=true;
	for(int i=1;i<=n;i++){
		if(vis[i]==false&&G[idx][i]){
			DFS(i,height+1);
		}
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		G[a][b]=G[b][a]=1;		
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			DFS(i,0);
			cnt++;
			if(cnt>1) break;
		}
	}
	if(cnt>1){
		cout<<"Error: "<<cnt<<" components"<<endl;
	}else{

//		set<int> tmp=ans;//使用set时会超时 
		int tmp[ans.size()],cnt=0;
		for(set<int>::iterator it=ans.begin();it!=ans.end();it++){
			tmp[cnt++]=*it;
		}
		maxH=0;
		fill(vis,vis+maxn,false);
		int st=*ans.begin();
		DFS(st,0);
//		for(set<int>::iterator it=tmp.begin();it!=tmp.end();it++){
//			ans.insert(*it);
//		}
		for(int i=0;i<cnt;i++){
			ans.insert(tmp[i]);
		}
		for(set<int>::iterator it=ans.begin();it!=ans.end();it++){
			cout<<*it<<endl;
		}
	}
	
	return 0;
}
