#include<cstdio>
#include<map>
using namespace std;

int main(){
	int k;
	scanf("%d",&k);
	while(k--){
		int n;
		scanf("%d",&n);
		bool flag=true;
		map<int,bool> mp;
		map<int,bool> mp1; 
		for(int i=1;i<=n;i++){
			int a;
			scanf("%d",&a);
			if(mp.find(a-i)==mp.end()){
				mp[a-i]=true;
			}else{
				flag=false;
			}
			if(mp1.find(a)==mp1.end()){
				mp1[a]=true;
			}else{
				flag=false;
			}
		}
		flag?printf("YES\n"):printf("NO\n");
	}
	
	return 0;
}
