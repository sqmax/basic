#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

//指针传递 
void change(int n,int* a,int* b){
	*a=*b=0;
	int num[4]={0},cnt=0;
	while(n>0){
		num[cnt++]=n%10;
		n/=10;
	}
	sort(num,num+4);
	for(int i=0;i<4;i++){
		*a=(*a)*10+num[4-1-i];
		*b=(*b)*10+num[i];
	}
} 
//引用传递 
//void change(int n,int& a,int& b){
//	a=0,b=0;
//	int num[4]={0},cnt=0;
//	while(n>0){
//		num[cnt++]=n%10;
//		n/=10;
//	}
//	
//	sort(num,num+4);
//	for(int i=0;i<4;i++){
//		a=a*10+num[4-1-i];
//		b=b*10+num[i];
//	}
//} 

int main(){
	int n;
	scanf("%d",&n);
	int a=0,b=0;
//	change(n,a,b);
	change(n,&a,&b);
	if(a==b){
		printf("%04d - %04d = 0000\n",n,n);
		return 0;
	}
	while(true){
		printf("%04d - %04d = %04d\n",a,b,a-b);
		if(a-b==6174){
			break;
		} 
//		change(a-b,a,b);
		change(a-b,&a,&b);	
		
	}
	
	return 0;
}
