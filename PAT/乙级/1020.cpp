#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1010;
struct Cake{
	double price;
	double amount,cost;
}cake[maxn];

bool cmp(Cake a,Cake b){
	return a.price>b.price; 
}
int main(){
	int n,d;
	scanf("%d %d",&n,&d);
	for(int i=0;i<n;i++){
		scanf("%lf",&cake[i].amount);
	}
	for(int i=0;i<n;i++){
		scanf("%lf",&cake[i].cost);
		cake[i].price=cake[i].cost/cake[i].amount;
	}
	sort(cake,cake+n,cmp);
	double sales=0;
	for(int i=0;i<n;i++){
		if(cake[i].amount<=d){
			sales+=cake[i].cost;
			d-=cake[i].amount;
		}else{
			sales+=d*cake[i].price;
			break;
		}
	}
	printf("%.2lf\n",sales);
	
	return 0;
} 
