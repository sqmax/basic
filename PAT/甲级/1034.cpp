//此题的难点在于DFS遍历每一个点后，都销毁走过的路径，不走回头路。 
//在递归时，不再以vis[i]==false问判断条件 ，因为vis[i]=true标记后，如果是环形图的话，那么最后一条边就不能访问到
//如A-B-C-A，刚开始时A被标记后，那么C-A这条边就不能在被访问到。 
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

const int maxn=2010;//不能定义为1010时，会有段错误，必须定义为2000以上，由于通话记录有1000条，因此不同的人可能有2000个 
struct Gang{
	int head;
	int num;
};
int G[maxn][maxn];
int W[maxn];
bool vis[maxn];
int n,K;
vector<Gang> ans;
map<string,int> stringToInt;
map<int,string> intToString;
int numPerson;
int maxConnTime;
void DFS(int idx,int &total,int &num,int &head){
	if(vis[idx]==false){
		num++;
		vis[idx]=true;
	}
	if(W[idx]>maxConnTime){
		maxConnTime=W[idx];
		head=idx;			
	}
	for(int i=0;i<numPerson;i++){
		if(G[idx][i]){//这里不在以vis[i]==false为条件，因为对于环形图访问不到最后一条边 
			total+=G[idx][i];
//			num++;
			G[idx][i]=G[i][idx]=0;//访问后销毁边 
			DFS(i,total,num,head);
		}
	}
}
//法二 :先访问边，再DFS遍历 
/** 
void DFS(int idx,int &total,int &num,int &head){
	num++;
	vis[idx]=true;
	if(W[idx]>maxConnTime){
		maxConnTime=W[idx];
		head=idx;			
	}
	for(int i=0;i<numPerson;i++){
		if(G[idx][i]){
			total+=G[idx][i];
			G[idx][i]=G[i][idx]=0;
			if(vis[i]==false){
				DFS(i,total,num,head);	
			} 
		}
	}
}
*/ 
bool cmp(Gang a,Gang b){
	return intToString[a.head]<intToString[b.head];
}
int transfer(string name){
	if(stringToInt.find(name)==stringToInt.end()){
		stringToInt[name]=numPerson;
		intToString[numPerson]=name;
		return numPerson++;
	}else{
		return stringToInt[name];
	}
}
int main(){
	cin>>n>>K;
	for(int i=0;i<n;i++){
		string a,b;
		int w;
		cin>>a>>b>>w;
		int aId=transfer(a);
		int bId=transfer(b);
		G[aId][bId]+=w;
		G[bId][aId]=G[aId][bId];
		W[aId]+=w;
		W[bId]+=w;
	}
	for(int i=0;i<numPerson;i++){
		if(vis[i]==false){
			int total=0,num=0,head;
			maxConnTime=0;
			DFS(i,total,num,head);
			if(total>K&&num>2){
				Gang gang;
				gang.head=head,gang.num=num;
				ans.push_back(gang);
			}	 
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<intToString[ans[i].head]<<" "<<ans[i].num<<endl;
	}
	
	return 0;
}
