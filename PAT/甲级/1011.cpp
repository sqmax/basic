#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	double ans=1;
	char bet[3];
	char posRes[3]={'W','T','L'};
	
	for(int i=0;i<3;i++){
		double maxOdd=0;
		for(int j=0;j<3;j++){
			double odd;
			scanf("%lf",&odd);
			if(odd>maxOdd){
				maxOdd=odd;
				bet[i]=posRes[j];
			}
			maxOdd=max(maxOdd,odd);
		}
		ans*=maxOdd;
	}
	printf("%c %c %c %.02f\n",bet[0],bet[1],bet[2],(ans*0.65-1)*2);
	
	return 0;
}
