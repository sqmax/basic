#include<cstdio>
#include<map>
#include<set>
using namespace std;

const int maxn=100010;
int Pair[maxn];
map<int,set<int> > mp;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	getchar();
	while(n--){
		int a,b;
		scanf("%d%d",&a,&b);
		mp[a].insert(b);
		mp[b].insert(a);
	}
	set<int> ship; 
	while(m--){
		int k;
		scanf("%d",&k);
		for(int i=0;i<k;i++){
			int a;
			scanf("%d",&a);
			ship.insert(a);
		}
		bool flg=true;
		for(set<int>::iterator it=ship.begin();it!=ship.end();it++){
			
			if(mp.find(*it)!=mp.end()){
				set<int> st=mp[*it];
				for(set<int>::iterator it2=st.begin();it2!=st.end();it2++){
					if(ship.find(*it2)!=ship.end()){
						flg=false;
						break;
					}
				}
			}
			if(flg==false) break;
//			printf("a:%d %d\n",*it,Pair[*it]);
//			if(ship.find(Pair[*it])!=ship.end()){
//				flg=false;
//				printf("%d\n",*it);
//				break;
//			}
		}
		if(flg) printf("Yes\n");
		else printf("No\n");
		ship.clear();
	}
} 
