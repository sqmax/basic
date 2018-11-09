#include<cstdio>

const int maxn=110;
int father[maxn];
bool isRoot[maxn]={false};

int findFather(int x){
	int a=x;
	while(father[x]!=x){
		x=father[x];
	}
	//Â·¾¶Ñ¹Ëõ 
	while(father[a]!=a){
		int t=a;
		a=father[a];
		father[t]=x;
	}
	return x;
}
void unionT(int a,int b){
	int fa=findFather(a);
	int fb=findFather(b);
	if(fa!=fb){
		father[fa]=fb;
	}
}
int main(){
	
	
	int n,m;
	scanf("%d %d",&n,&m);

	for(int i=1;i<=n;i++){
		father[i]=i;
	}	
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		unionT(a,b);
	}
//	for(int i=1;i<=n;i++){
//		printf("fa:%d\n",findFather(i));
//	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		isRoot[findFather(i)]=true;		
	}
	for(int i=1;i<=n;i++){
		if(isRoot[i]==true){
			cnt++;
		}
	}
	printf("%d\n",cnt);
	
	return cnt;
} 
