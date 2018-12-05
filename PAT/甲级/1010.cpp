#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int toDecimal(char a[],int radix){
	int rnt=0;
	for(int i=0;i<strlen(a);i++){
		int t;
		if(a[i]>='a'){
			t=a[i]-'a'+10;
		}else{
			t=a[i]-'0';
		}
		rnt=rnt*radix+t;
	}	
	return rnt;
}

int main(){
	char n1[10],n2[10];
	char tag,rad;
	scanf("%s %s %c %c",&n1,&n2,&tag,&rad);
	
	if(tag=='2'){
		swap(n1,n2);
	}
	int r;
	for(int i=0;i<)
	int x=toDecimal(n1,r);
	
	bool flag=false;
	char maxRad='0';
	for(int i=0;i<strlen(n2);i++){
		if(n2[i]>maxRad){
			maxRad=n2[i];
		}
	}
	maxRad++;
	int i;
	if(maxRad>='a'){
		i=maxRad-'a'+10;
	}else{
		i=maxRad-'0';
	}
	for(i=2;i<36;i++){
		int y=toDecimal(n2,i);
//		printf("%d\n",y);
		if(x==y){
			printf("%c\n",i);
			flag=true;
			break;
		}else if(y>x){
			break;
		}
	}
	if(flag==false){
		printf("Impossible\n");
	}
	return 0;
}
