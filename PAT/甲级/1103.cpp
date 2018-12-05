#include<cstdio>
#include<vector>
#include<cmath> 
using namespace std;

vector<int> fac;
vector<int> tmpList,baseList;
int maxBaseSum=0;
int N,K,P;
void init(){
	for(int i=0;pow(i,P)<=N;i++){
		fac.push_back(pow(i,P));
	}
}
/*
*index ��β��ͷ����fac���� 
*cntK ���Ӹ���
*facSum ���Ӻ�
*baseSum ���ӵ�����
*/
void DFS(int index,int cntK,int facSum,int baseSum){
	if(facSum==N&&cntK==K){
		if(baseSum>maxBaseSum){
			maxBaseSum=baseSum;
			baseList=tmpList;
		}
		return;
	}else if(facSum>N||cntK>K){
		return;
	}
	if(index>=1){
		tmpList.push_back(index);
		DFS(index,cntK+1,facSum+fac[index],baseSum+index);
		tmpList.pop_back();
		DFS(index-1,cntK,facSum,baseSum);
	}
}
int main(){
	scanf("%d%d%d",&N,&K,&P);
	init();
	int index=fac.size()-1;
	DFS(index,0,0,0);
	
	if(maxBaseSum==0){
		printf("Impossible\n");
	}else{
		printf("%d = ",N);
		printf("%d^%d",baseList[0],P);
		for(int i=1;i<baseList.size();i++){
			printf(" + %d^%d",baseList[i],P);
		}
	}
	
	return 0;
}
