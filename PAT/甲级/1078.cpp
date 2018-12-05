//最后一个测试点错误，求助 
#include<cstdio>
#include<cmath>
using namespace std;

const int maxn=10010;
int a[maxn];
bool occupied[maxn];

bool isPrime(int x){
	if(x<=1) return false;
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0) return false;
	}
	return true;
}

int main(){
	int mSize,n;
	scanf("%d%d",&mSize,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}	
	while(!isPrime(mSize)){
		mSize++;
	}
	bool first=true;
	for(int i=0;i<n;i++){
		int pos=a[i]%mSize;
		if(occupied[pos]==false){
			if(first) first=false;
			else printf(" ");
			printf("%d",pos);
			occupied[pos]=true;
		}else{
			bool flag=false;
			for(int j=1;j<mSize;j++){
				pos=(a[i]+j*j)%mSize;
				if(occupied[pos]==false){
					if(first) first=false;
					else printf(" ");
					printf("%d",pos);
					occupied[pos]==true;
					flag=true;
					break;
				}
			}
			if(first) first=false;
			else printf(" ");
			if(flag==false) printf("-");
		}	
	}
	
	return 0;
}
