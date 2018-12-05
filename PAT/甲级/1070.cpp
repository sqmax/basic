#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1010;
struct MoonCake{
	double stock,cost,price;
}cake[maxn];
bool cmp(MoonCake a,MoonCake b){
	return a.price>b.price;
}
int main(){
	int n;
	scanf("%d",&n);
	double d;
	scanf("%lf",&d);
	for(int i=0;i<n;i++){
		scanf("%lf",&cake[i].stock);
	}
	for(int i=0;i<n;i++){
		scanf("%lf",&cake[i].cost);
		cake[i].price=cake[i].cost/cake[i].stock;
	}
	sort(cake,cake+n,cmp);
	double ans=0;
	for(int i=0;i<n;i++){
		if(cake[i].stock<=d){
			ans+=cake[i].cost;
			d-=cake[i].stock;
		}else{
			ans+=cake[i].price*d;
			break;
		}
	}
	printf("%.02f\n",ans);
	
	return 0;
}
