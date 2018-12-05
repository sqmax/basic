#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=100010;
int coupon[maxn],product[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int nc,np;
	cin>>nc;
	for(int i=0;i<nc;i++){
		cin>>coupon[i];
	}
	cin>>np;
	for(int i=0;i<np;i++){
		cin>>product[i];
	}
	sort(coupon,coupon+nc,cmp);
	sort(product,product+np,cmp);
	int sum=0;
	int i=0,j=0;
	while(i<nc&&j<np&&coupon[i]>0&&product[i]>0){
		sum+=coupon[i]*product[j];
		i++;
		j++;
	}
	i=nc-1,j=np-1;
	while(i>=0&&j>=0&&coupon[i]<0&&product[j]<0){
		sum+=coupon[i]*product[j];
		i--;
		j--;
	}
	cout<<sum<<endl;
	
	return 0;
}
