#include<cstdio>

int findGreatestSumOfArray(int* pData,int len){
	int curSum=0;
	int greatestSum=-1;
	for(int i=0;i<len;i++){
		if(curSum<=0){
			curSum=pData[i];
		}else{
			curSum+=pData[i];
		}
		if(curSum>greatestSum){
			greatestSum=curSum;
		}
	}
	return greatestSum;
} 
int dp[100];
int findGreatestSumOfArray1(int* pData,int len){
	dp[0]=pData[0];
	int greatest=-1;
	for(int i=1;i<len;i++){
		if(dp[i-1]<0){
			dp[i]=pData[i];
		}else{
			dp[i]=dp[i-1]+pData[i];
		}
		
		if(dp[i]>greatest){
			greatest=dp[i];
		}
	}
	return greatest;
}
int main(){
	int a[]={1,-2,3,10,-4,7,2,-5};
	int max=findGreatestSumOfArray(a,8);
	printf("max:%d\n",max);
	
	int max1=findGreatestSumOfArray1(a,8);
	printf("max1:%d\n",max1);
	
	return 0;
} 
