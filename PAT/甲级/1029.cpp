#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=200010;
int a[maxn],b[maxn];

int main(){
	int n1,n2;
	cin>>n1;
	for(int i=0;i<n1;i++){
		cin>>a[i];
	}
	cin>>n2;
	for(int i=0;i<n2;i++){
		cin>>b[i];
	}
	int mid;
	if((n1+n2)%2) mid=(n1+n2)/2;
	else mid=(n1+n2)/2-1;
	int i=0,j=0,cnt=0;
	while(i<n1&&j<n2){
		if(a[i]<b[j]){
			i++;
		}else{
			j++;
		}
		cnt++;
		if(cnt==mid) break;
	}
	if(i==n1){
		cout<<b[mid-n1];
	}else if(j==n2){
		cout<<a[mid-n2];
	}else{
		cout<<min(a[i],b[j]);
	}
	
	return 0;
}
