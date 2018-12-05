#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100010;
int num[maxn];
int search(int a[],int n,int x){
	int left=0,right=n-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(x<a[mid]){
			right=mid-1;
		}else if(x>a[mid]){
			left=mid+1;
		}else{
			return mid;
		}
	}
	return -1;
}
int main(){
	int n;
	scanf("%d",&n);
	int maxN=0;
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		if(num[i]>maxN){
			maxN=num[i];
		}
	}
	sort(num,num+n);
	for(int i=1;i<=maxN+1;i++){
		int pos=search(num,n,i);
		if(pos==-1){
			printf("%d\n",i);
			break;
		}
		
	}
	return 0;
} 
