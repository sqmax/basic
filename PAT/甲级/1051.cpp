#include<cstdio>
#include<stack>
using namespace std;

int main(){
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	
	while(k--){
		int a[n];
		stack<int> st;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int p=0;
		bool flg=true;
		for(int i=1;i<=n;i++){
			if(st.size()<m) st.push(i);
			else{
				flg=false;
				break;
			}
			while(!st.empty()&&st.top()==a[p]){
				p++;
				st.pop();
			}
		}
		if(!st.empty()) flg=false;
		if(flg==true) printf("YES\n");
		else printf("NO\n"); 
	}
	
	return 0;
}
