#include<cstdio>
#include<stack>
using namespace std;

bool isPopOrder(int* pPush,int* pPop,int len){
	bool flag=false;
	if(pPush!=NULL&&pPop!=NULL&&len>0){
		int* pNextPush=pPush;
		int* pNextPop=pPop;
		
		stack<int> stackData;
		
		while(pNextPop-pPop<len){
			while(stackData.empty()||stackData.top()!=*pNextPop){
				if(pNextPush-pPush==len){
					break;
				}
				stackData.push(*pNextPush);
				pNextPush++;
			}
			if(stackData.top()!=*pNextPop){
				break;
			}
			stackData.pop();
			pNextPop++;
		}
		if(stackData.empty()&&pNextPop-pPop==len){
			flag=true;
		}
	}
	return flag;
}
int main(){
	
	int a[]={1,2,3,4,5};
	int b[]={4,5,3,2,1};
	bool res=isPopOrder(a,b,5);
	
	printf("res:%d",res);
	return 0;
} 
