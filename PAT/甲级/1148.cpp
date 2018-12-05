#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	vector<int> assert(n+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&assert[i]);
	}
	for(int i=1;i<=n;i++){//不断地假设两个狼人i，j 
		for(int j=i+1;j<=n;j++){
			vector<int> liar,actual(n+1,1);
			actual[i]=actual[j]=-1;//狼人用-1表示，好人1 
			for(int k=1;k<=n;k++){
				if(assert[k]*actual[abs(assert[k])]<0){//k说的话与实际不符，则k为骗子 
					liar.push_back(k);
				}
			}
			if(liar.size()==2&&actual[liar[0]]+actual[liar[1]]==0){
				printf("%d %d\n",i,j);
				return 0;
			}
		}
	}
	printf("No Solution\n");
	
	return 0;
} 
