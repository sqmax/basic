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
	for(int i=1;i<=n;i++){//���ϵؼ�����������i��j 
		for(int j=i+1;j<=n;j++){
			vector<int> liar,actual(n+1,1);
			actual[i]=actual[j]=-1;//������-1��ʾ������1 
			for(int k=1;k<=n;k++){
				if(assert[k]*actual[abs(assert[k])]<0){//k˵�Ļ���ʵ�ʲ�������kΪƭ�� 
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
