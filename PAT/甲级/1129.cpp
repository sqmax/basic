#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

const int maxn=50010;
struct Node{
	int key,count;
	
}node[maxn];
bool cmp(Node a,Node b){
	if(a.count!=b.count){
		return a.count>b.count;
	}else{
		return a.key<b.key;
	}
} 
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	map<int,int> mp;
	int a,before;
	for(int i=0;i<n;i++){
		before=a;
		int cnt;
		if(i>0){
			if(mp.find(before)==mp.end()){
				mp[before]=1;
			}else{
				mp[before]++;
			}
			cnt=0;
			for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
				node[cnt].key=it->first;
				node[cnt++].count=it->second;
			}
			sort(node,node+cnt,cmp);
			
		}
		scanf("%d",&a);
		if(i>0){
			printf("%d:",a);
			for(int i=0;i<cnt&i<k;i++){
				printf(" %d",node[i].key);
			}
			printf("\n");
		}
	}
}
