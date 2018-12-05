#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=510;
const int INF=0x3fffffff;
struct Station{
	double price,dis;
}sta[maxn];
bool cmp(Station a,Station b){
	return a.dis<b.dis;
}
int main(){
	double Cmax,D,Davg;
	int n;
	cin>>Cmax>>D>>Davg>>n;
	for(int i=0;i<n;i++){
		cin>>sta[i].price>>sta[i].dis;
	}	
	sta[n].dis=D;
	sta[n].price=0;
	sort(sta,sta+n,cmp);
	
	if(sta[0].dis!=0){
		cout<<"The maximum travel distance = 0.00\n";
	}else{
		int now=0;
		double ans=0,nowTank=0,MAX=Cmax*Davg;
		while(now<n){
			int k=-1;
			double priceMin=INF;
			for(int i=now+1;i<=n&&sta[i].dis-sta[now].dis<=MAX;i++){
				if(sta[i].price<priceMin){
					priceMin=sta[i].price;
					k=i;
					if(priceMin<sta[now].price){
						break;
					}
				}
			}
			if(k==-1) break;
			double need=(sta[k].dis-sta[now].dis)/Davg;
			if(priceMin<sta[now].price){
				if(nowTank<need){
					ans+=(need-nowTank)*sta[now].price;
					nowTank=0;
				}else{
					nowTank-=need;
				}
			}else{
				ans+=(Cmax-nowTank)*sta[now].price;
				nowTank=Cmax-need;
			}
			now=k;
		} 
		if(now==n){
			printf("%.2f\n",ans);
		}else{
			printf("The maximum travel distance = %.2f\n",sta[now].dis+MAX);
		}
	}

	return 0;
}
