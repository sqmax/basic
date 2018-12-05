#include<iostream>
#include<string>
using namespace std;

const int maxn=1010;
int dp[maxn][maxn];

int main(){
	string s;
	getline(cin,s);
	int ans=1;
	int len=s.length();
	for(int i=0;i<len;i++){
		dp[i][i]=1;
		if(i<len-1){
			if(s[i]==s[i+1]){
				dp[i][i+1]=1;
				ans=2;
			}
		}
	}
	for(int L=3;L<=len;L++){
		for(int i=0;i+L-1<len;i++){
			int j=i+L-1;
			if(s[i]==s[j]&&dp[i+1][j-1]==1){
				dp[i][j]=1;
				ans=L;
			}
		}
	}
	printf("%d\n",ans);
	
	return 0;
}
