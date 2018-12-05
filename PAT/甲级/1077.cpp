#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=110;
string stc[maxn];

int main(){
	int n;
	scanf("%d",&n);
	int minLen=300;
	getchar();
	for(int i=0;i<n;i++){
		getline(cin,stc[i]);
		reverse(stc[i].begin(),stc[i].end());
//		minLen=max(minLen,stc[i].size()); 
		if(stc[i].length()<minLen) minLen=stc[i].length();
	}
	string ans="";
	for(int i=0;i<minLen;i++){
		char ch=stc[0][i];
		bool flg=true;
		for(int j=1;j<n;j++){
			if(stc[j][i]!=ch){
				flg=false;
				break;	
			}
		}
		if(flg){
			ans+=ch;
		}else{
			break;
		}
	}
	reverse(ans.begin(),ans.end());
	if(ans=="") cout<<"nai"<<endl;
	else cout<<ans<<endl;
	
}
