//最后一个测试点错误，求助 
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=10010;
int coins[maxn];

int n,m;
vector<int> ans,temp;
bool flag=false;
void findCoins(int index,int sum){
	if(index>n) return;
	if(flag==true) return;
	if(sum==0||(index==n&&sum==coins[n-1])){
		flag=true;
		ans=temp;
		return;
	}else if(sum<0){
		return;
	}
	temp.push_back(coins[index]);
	findCoins(index+1,sum-coins[index]);
	temp.pop_back();
	findCoins(index+1,sum);
} 
int main(){
	
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&coins[i]);
	}
	sort(coins,coins+n);
	findCoins(0,m);
	
	if(ans.size()==0) printf("No Solution\n");
	else{
		for(int i=0;i<ans.size();i++){
			printf("%d",ans[i]);
			if(i<ans.size()-1) printf(" ");
		}	
	}
	
	return 0;
} 
