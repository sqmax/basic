#include<cstdio>
#include<algorithm>
using namespace std; 

const int maxn=110;
struct Fraction{
	int up,down;
	Fraction(){
		up=0,down=1;
	}
}fac[maxn];
int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
Fraction simply(Fraction a){
	if(a.up==0){
		a.down=1;
	}else{
		int g=gcd(abs(a.up),abs(a.down));
		a.up/=g;
		a.down/=g;
	}
	return a;
}
Fraction add(Fraction a,Fraction b){
	Fraction ans;
	a=simply(a);
	b=simply(b);
	ans.up=a.up*b.down+b.up*a.down;
	ans.down=a.down*b.down;
	
	return simply(ans);
}
void print(Fraction a){
	a=simply(a);
	if(a.down==1){
		printf("%d\n",a.up);
	}else if(abs(a.up)>abs(a.down)){
		printf("%d %d/%d\n",a.up/a.down,abs(a.up)%abs(a.down),a.down);
	}else{
		printf("%d/%d\n",a.up,a.down);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	Fraction sum;
	for(int i=0;i<n;i++){
		scanf("%d/%d",&fac[i].up,&fac[i].down);
		sum=add(sum,fac[i]);
	}
	
	print(sum);
	
	return 0;
	
}
