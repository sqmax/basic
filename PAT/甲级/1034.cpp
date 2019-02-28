//������ѵ�����DFS����ÿһ����󣬶������߹���·�������߻�ͷ·�� 
//�ڵݹ�ʱ��������vis[i]==false���ж����� ����Ϊvis[i]=true��Ǻ�����ǻ���ͼ�Ļ�����ô���һ���߾Ͳ��ܷ��ʵ�
//��A-B-C-A���տ�ʼʱA����Ǻ���ôC-A�����߾Ͳ����ڱ����ʵ��� 
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

const int maxn=2010;//���ܶ���Ϊ1010ʱ�����жδ��󣬱��붨��Ϊ2000���ϣ�����ͨ����¼��1000������˲�ͬ���˿�����2000�� 
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
		if(G[idx][i]){//���ﲻ����vis[i]==falseΪ��������Ϊ���ڻ���ͼ���ʲ������һ���� 
			total+=G[idx][i];
//			num++;
			G[idx][i]=G[i][idx]=0;//���ʺ����ٱ� 
			DFS(i,total,num,head);
		}
	}
}
//���� :�ȷ��ʱߣ���DFS���� 
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
