#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=10010;
struct Player{
	char arriveT[20];
	int playT;
	bool vip;	
}player[maxn];
bool cmp(Player a,Player b){
	return strcmp(a.arriveT,b.arriveT)<0;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %d %d",player[i].arriveT,&player[i].playT,&player[i].vip);
	}
	sort(player,player+n,cmp);
	printf("---------\n");
	for(int i=0;i<n;i++){
		printf("%s %d %d\n",player[i].arriveT,player[i].playT,player[i].vip);
	}
	
	
}
