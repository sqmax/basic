#include<cstdio>
#include<map>
#include<set>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	map<int,int> couple;
	while(n--){
		int a,b;
		scanf("%d%d",&a,&b);
		couple[a]=b;
		couple[b]=a;
	}
	int m;
	scanf("%d",&m);
	set<int> guests;
	for(int i=0;i<m;i++){
		int a;
		scanf("%d",&a);
		guests.insert(a);
	}
	set<int> ans;
	for(set<int>::iterator it=guests.begin();it!=guests.end();it++){
		if(couple.find(*it)!=couple.end()&&guests.find(couple[*it])!=guests.end()){
			
		}else{
			ans.insert(*it);
		}
	}
	printf("%d\n",ans.size());
	for(set<int>::iterator it=ans.begin();it!=ans.end();it++){
		printf("%05d",*it);
		if(it!=--ans.end()){
			printf(" ");
		}
	}
	return 0;
}
