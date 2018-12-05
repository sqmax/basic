#include<cstdio>
#include<cmath>

const int maxn=10010;
int hTable[maxn]={0};

bool isPrime(int x){
	if(x<=1) return false;
	for(int i=2;i<=(int)sqrt(x);i++){
		if(x%i==0){
			return false;
		}
	}	
	return true;
}
int main(){
	int mSize,n,m;
	scanf("%d%d%d",&mSize,&n,&m);
	while(true){
		if(isPrime(mSize)==true&&mSize>=n){
			break;
		}
		mSize++;
	}
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		int j;
		for(j=0;j<mSize;j++){
			int pos=(a+j*j)%mSize;
			if(hTable[pos]==0){
				hTable[pos]=a;
				break;
			}
		}
		if(j==mSize){
			printf("%d cannot be inserted.\n",a);
		}
	}
	double sum=0;
	for(int i=0;i<m;i++){
		int a;
		scanf("%d",&a);
		int j=0;
		for(;j<mSize;j++){
			int pos=(a+j*j)%mSize;
			if(hTable[pos]==a||hTable[pos]==0){
				break;
			}
		}
		sum+=j+1;
		
	}
	sum/=m;
	printf("%.1lf\n",sum+0.05);
	
	return 0;
} 
