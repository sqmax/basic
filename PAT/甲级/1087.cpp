#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;

const int maxn=1010;
const int INF=0x3fffffff;
int G[maxn][maxn];
int happiness[maxn];
int d[maxn];
bool vis[maxn];
vector<int> pre[maxn];
int n,start,dest;

map<string,int> strToInt;
map<int,string> intToStr;
int cnt=0;
int transfer(string s){
	if(strToInt.find(s)==strToInt.end()){
		strToInt[s]=cnt;
		intToStr[cnt]=s;
		return cnt++;
	}else{
		return strToInt[s];
	}
}
void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<MIN){
				MIN=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];	
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+G[u][v]==d[v]){
					pre[v].push_back(u);
				}
				
			}
		}
	}
}
vector<int> ans,temp;
int mostHap=0;
double aveHap=0;
int route=0;
void DFS(int des){
	if(des==start){
		route++;
		temp.push_back(des);
		int tmpHap=0;
		for(int i=0;i<temp.size();i++){
			tmpHap+=happiness[temp[i]];
		}
		if(tmpHap>mostHap){
			ans=temp;
			mostHap=tmpHap;
			aveHap=mostHap*1.0/(temp.size()-1);
		}else if(tmpHap==mostHap){
			if(temp.size()<ans.size()){
				ans=temp;
				aveHap=mostHap*1.0/(temp.size()-1);
			}
		}
		temp.pop_back();
		return;
	}
	temp.push_back(des);
	for(int i=0;i<pre[des].size();i++){
		int preC=pre[des][i];
		DFS(preC);
	}
	temp.pop_back();
}
int main(){
	int k;
	string st;
	cin>>n>>k>>st;
	start=transfer(st);
	dest=transfer("ROM");
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<n-1;i++){
		string city;
		int hap;
		cin>>city>>hap;
		int cityN=transfer(city);
		happiness[cityN]=hap;
	}
	for(int i=0;i<k;i++){
		string c1,c2;
		int cost;
		cin>>c1>>c2>>cost;
		int no1=transfer(c1);
		int no2=transfer(c2);
		G[no1][no2]=G[no2][no1]=cost;
	}
	Dijkstra(start);
	
	DFS(dest);
	
	cout<<route<<" "<<d[dest]<<" "<<mostHap<<" "<<(int)aveHap<<endl;
	for(int i=ans.size()-1;i>0;i--){
		cout<<intToStr[ans[i]]<<"->";
	}
	cout<<"ROM"<<endl;
	
	return 0;
} 
