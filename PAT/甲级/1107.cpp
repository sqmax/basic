#include<cstdio>
#include<algorithm>
#include<vector> 
using namespace std;

const int maxn=1010;
int father[maxn];
int cluster[maxn];
int hobby[maxn];

void init(){
	for(int i=0;i<maxn;i++){
		father[i]=i;
	}
}
int findFather(int x){
	int tmp=x;
	while(father[x]!=x){
		x=father[x];
	}
	
	while(father[tmp]!=x){
		int t=father[tmp];;
		father[tmp]=x;
		tmp=t;	
	}
	return x;
}
void unionAB(int a,int b){
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA<faB){
		father[faB]=faA;
	}else if(faA>faB){
		father[faA]=faB;
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n;
	scanf("%d",&n);
	init();
	int maxK=0;
	for(int i=0;i<n;i++){
		int k,a,b;
		scanf("%d: %d",&k,&a);
		maxK=max(a,maxK);
		hobby[i]=a;
		for(int j=1;j<k;j++){
			scanf("%d",&b);
			maxK=max(b,maxK);
			unionAB(a,b);
		}
	}
	for(int i=0;i<n;i++){
		cluster[findFather(hobby[i])]++;
	}
	sort(cluster,cluster+maxK+1,cmp);//细心：cluster+maxK+1不是cluster+maxK，否则有几个测试点错误，很隐蔽。 
	int cnt=0;
	for(int i=0;i<maxK;i++){
		if(cluster[i]) cnt++;
		else break;
	}
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		printf("%d",cluster[i]);
		if(i<cnt-1) printf(" ");
	}

	return 0;
}
