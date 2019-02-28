#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int c=a+b;
	if(c/1000000){
		printf("%d,%03d,%03d\n",c/1000000,abs(c)%1000000/1000,abs(c)%1000);
	}else if(c/1000){
		printf("%d,%03d\n",c/1000,abs(c)%1000);
	}else{
		printf("%d\n",c);
	}
	return 0;
} 
