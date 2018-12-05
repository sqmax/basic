#include<cstdio>
#include<set>
using namespace std;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int edg1[m],edg2[m];
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		edg1[i]=a;
		edg2[i]=b;
//		st1.insert(a);
//		st2.insert(b);
	}
	int k;
	scanf("%d",&k);
	while(k--){
		int nv;
		scanf("%d",&nv);
		set<int> st;
		for(int i=0;i<nv;i++){
			int a;
			scanf("%d",&a);
			st.insert(a);
		}
		bool flag=true;
//		set<int>::iterator it1=st1.begin();
//		set<int>::iterator it2=st2.begin();
		for(int i=0;i<m;i++){
			if(st.find(edg1[i])==st.end()&&st.find(edg2[i])==st.end()){
				flag=false;
				break;
			}
		}
		flag?printf("Yes\n"):printf("No\n");
	}
	
	return 0;
}
