#include<cstdio>

const int maxn=1010;

void printN(int a,bool flag){
	if(flag==false){
		printf("N");
	}else{
		printf("%d",a);
	}
}
int main(){
	
	int n;
	scanf("%d",&n);
	int a1=0,a2=0,a3=0,a5=0;
	bool exit1=false,exit2=false,exit3=false,exit4=false,exit5=false; 
	double a4=0.0;
	int flag=1,cnt=0;
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		if(t%5==0&&t%2==0){
			a1+=t;
			exit1=true;
		}
		if(t%5==1){
			a2+=flag*t; 
			flag=-flag;
			exit2=true;
		}
		if(t%5==2){
			a3++;
			exit3=true;
		} 
		if(t%5==3){
			a4+=t;
			cnt++;
			exit4=true;
		}
		if(t%5==4){
			if(t>a5){
				a5=t;
			}
			exit5=true;
		}
	}
	a4/=cnt;
	printN(a1,exit1);
	printf(" ");
	
	printN(a2,exit2);
	printf(" ");
	
	printN(a3,exit3);
	printf(" ");
	
	if(exit4){
		printf("%.1lf ",a4);	
	}else{
		printf("N ");
	}
	
	printN(a5,exit5);
	
	return 0;
}
