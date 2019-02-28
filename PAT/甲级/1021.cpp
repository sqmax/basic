//˼·��n���ڵ��ͼ��n-1���ߣ����ͼ����ͨ�Ļ����Ǹ�ͼһ����һ����
//�ж��Ƿ���ͨ�����ò��鼯��Ҳ����������DFS
//�����Ļ�ѡ��һ�����Ϊ�����������ģ��ɵõ���������ĸ�
//Ȼ���ԴӲ�������ĸ���ѡȡ1��Ϊ�������ٴ�������ȱ��������ٴεõ���������ĸ�
//���εĲ�����Ϊ��������ĸ� 

//�ҿ�ʼ���ж�ͼ��ͨ�󣬶����нڵ����������ȱ������������ᳬʱ�� 
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

//		set<int> tmp=ans;//ʹ��setʱ�ᳬʱ 
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
