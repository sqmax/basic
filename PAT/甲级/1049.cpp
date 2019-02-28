#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main(){
	int n,a=1,ans=0;
	int left,now,right;
	cin>>n;
	while(n/a!=0){
		left=n/(a*10);
		now=n/a%10;
		right=n%a;
		
		if(now==0) ans+=left*a;
		else if(now==1) ans+=left*a+right+1;
		else ans+=(left+1)*a;
		a*=10;
	}
	cout<<ans;
	return 0;
}
//int contains1(int x){
//	int cnt=0;
//	while(x){
//		int a=x%10;
//		if(a==1){
//			cnt++;
//		}
//		x/=10;
//	}
//	return cnt;
//}
//int main(){
//	int n;
//	scanf("%d",&n);
//	int cnt=0;
//	for(int i=1;i<=n;i++){
//		cnt+=contains1(i);
//	}
//	printf("%d\n",cnt);
//	
//	return 0;
//} 

