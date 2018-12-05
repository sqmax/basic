#include<cstdio>
#include<cmath>
using namespace std;

const int maxn=10010;
int mark[maxn];

bool isPrime(int x){
	if(x<=1) return false;
	for(int i=2;i<=(int)sqrt(x);i++){
		if(x%i==0) return false;
	}
	return true;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		if(i==1){
			mark[a]=1;
		}else if(isPrime(i)){
			mark[a]=2;
		}else{
			mark[a]=3;
		}
	}		
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int a;
		scanf("%d",&a);
		if(mark[a]==1){
			printf("%04d: Mystery Award\n",a);
			mark[a]=-1;
		}else if(mark[a]==2){
			printf("%04d: Minion\n",a);
			mark[a]=-1;
		}else if(mark[a]==3){
			printf("%04d: Chocolate\n",a);
			mark[a]=-1;
		}else if(mark[a]==-1){
			printf("%04d: Checked\n",a);
		}else{
			printf("%04d: Are you kidding?\n",a);
		}
		
	}
	return 0;
}
