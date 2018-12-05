#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=3010;//不能定义1010，否则3，4测试点错误，一定要注意数组边界 
struct Node{
	int exp;
	double coe;
}poly1[maxn],poly2[maxn];
double ans[maxn];

int main(){
	int k1,k2,exp;
	double coe;
	scanf("%d",&k1);
	for(int i=0;i<k1;i++){
		scanf("%d %lf",&poly1[i].exp,&poly1[i].coe);
	}
	scanf("%d",&k2);
	for(int i=0;i<k2;i++){
		scanf("%d %lf",&poly2[i].exp,&poly2[i].coe);
	}	
	int maxE=0;
	for(int i=0;i<k1;i++){
		for(int j=0;j<k2;j++){
			exp=poly1[i].exp+poly2[j].exp;
			coe=poly1[i].coe*poly2[j].coe;
			ans[exp]+=coe;
			maxE=max(exp,maxE);
//			printf("%d %.1f ",exp,coe);
		}
	}
	int cnt=0;
	for(int i=maxE;i>=0;i--){
		if(ans[i]!=0.0){
			cnt++;
		}
	}
	printf("%d",cnt);
	for(int i=maxE;i>=0;i--){
		if(ans[i]!=0.0){
			printf(" %d %.01f",i,ans[i]);
		}
	}
	return 0;
}
