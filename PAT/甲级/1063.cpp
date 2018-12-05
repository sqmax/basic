#include<cstdio>
#include<set>
using namespace std;

const int maxn=51;
set<int> num[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int m;
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			int a;
			scanf("%d",&a);
			num[i].insert(a);
		}
	}
	int k;
	scanf("%d",&k);
	while(k--){
		int a,b;
		scanf("%d%d",&a,&b);
		int sum=num[a].size()+num[b].size();
		set<int> ab;
		for(set<int>::iterator it=num[a].begin();it!=num[a].end();it++){
			ab.insert(*it);
		}
		for(set<int>::iterator it=num[b].begin();it!=num[b].end();it++){
			ab.insert(*it);
		}
		int unique=ab.size();
		printf("%.01f%\n",100.0*(sum-unique)/unique);
	}
	
	return 0;
} 
