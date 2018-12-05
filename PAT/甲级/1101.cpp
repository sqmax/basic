#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=100010;
int num[maxn];
int leftMax[maxn],rightMin[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		if(i>0){
			if(num[i]>leftMax[i-1]){
				leftMax[i]=num[i];
			}else{
				leftMax[i]=leftMax[i-1];
			}
		}		
	}
	rightMin[n-1]=num[n-1];
	for(int i=n-1;i>=0;i--){
		if(i<n-1){
			if(num[i]<rightMin[i+1]){
				rightMin[i]=num[i];
			}else{
				rightMin[i]=rightMin[i+1];
			}
		}
	}
	vector<int> ans;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(num[i]>=leftMax[i]&&num[i]<=rightMin[i]){
			ans.push_back(num[i]);
			cnt++;
		}
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		printf("%d",ans[i]);
		if(i<cnt-1) printf(" ");
	}
	printf("\n");//这里要输个空行否则一个测试点格式错误 
	return 0;
}
