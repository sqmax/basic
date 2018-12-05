//Á½¸ö²âÊÔµã´íÎó 
#include<cstdio>
#include<set>
using namespace std;

const int maxn=10010;
int father[maxn];

int findFather(int x){
	int tmp=x;
	while(father[x]!=x){
		x=father[x];
	} 
	while(father[tmp]!=x){
		int fa=father[tmp];
		father[tmp]=x;
		tmp=fa;
	}
	return x;
}
void unionAB(int a,int b){
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB) father[faB]=faA;
}
void init(){
	for(int i=0;i<maxn;i++){
		father[i]=i;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	
	set<int> birds;
	init();
	
	while(n--){
		int k;
		int a,b;
		scanf("%d%d",&k,&a);
		birds.insert(a);
		for(int i=1;i<k;i++){
			scanf("%d",&b);
			unionAB(a,b);		
			birds.insert(b);
		}
	}
	int trees=0;
	for(set<int>::iterator it=birds.begin();it!=birds.end();it++){
//		printf("F:%d %d ",*it,findFather(*it));
		if(findFather(*it)==*it){
			trees++;
		}
	}
	printf("%d %d\n",trees,birds.size());
	
	int k;
	scanf("%d",&k);
	while(k--){
		int a,b;
		scanf("%d %d",&a,&b);
		int faA=findFather(a);
		int faB=findFather(b);
		if(faA==faB) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
} 
