#include<cstdio>
#include<algorithm>
using namespace std;

bool covered[100000];

bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n;
	scanf("%d",&n);
	int a[110];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		int t=a[i];

		while(t!=1){
			if(t%2){
				t=(3*t+1)/2;
			}else{
				t/=2;
			}
			//if(t>100) continue;
			covered[t]=true;
		}
	}
	sort(a,a+n,cmp);
	int cnt=0;
	for(int i=0;i<n;i++){
		if(covered[a[i]]==false){
			cnt++;
		}
	}
	for(int i=0;i<n;i++){
		if(covered[a[i]]==false){		
			printf("%d",a[i]);	
			cnt--;
			if(cnt>0) printf(" ");		
		}
	}
	return 0;	

} 
