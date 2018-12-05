#include<cstdio>

char unit[14]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("#%c%c%c%c%c%c\n",unit[a/13],unit[a%13],unit[b/13],unit[b%13],unit[c/13],unit[c%13]);
	
	return 0;
}
