#include<cstdio>
#include<algorithm>
using namespace std;

void printMostPosture(int a[]){
	int maxM=max(a[0],max(a[1],a[2]));
	if(a[2]==maxM){
		printf("B");
	}else if(a[0]==maxM){
		printf("C");
	}else if(a[1]==maxM){
		printf("J");
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int aWin=0,same=0;
	int wa[3]={0},wb[3]={0};
	int i=n;
	while(i--){
		char A,B;
		getchar();
		scanf("%c %c",&A,&B);
		int a=(A=='C'?0:(A=='J'?1:2));
		int b=B=='C'?0:(B=='J'?1:2);
	
//		printf("%d %d\n",a,b);
		if(a==b){
			same++;
		}else if((a+1)%3==b){
			aWin++;
			wa[a]++;
		}else{
			wb[b]++;
		}
	}
	printf("%d %d %d\n",aWin,same,n-aWin-same);
	printf("%d %d %d\n",n-aWin-same,same,aWin);
	printMostPosture(wa);
	printf(" ");
	printMostPosture(wb);
	
	return 0;
}
