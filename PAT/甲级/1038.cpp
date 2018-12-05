#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int maxn=10010;
string num[maxn];
bool cmp(string a,string b){
	return a+b<b+a;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}	
	sort(num,num+n,cmp);
	string ans;
	for(int i=0;i<n;i++){
		ans+=num[i];
	}
	while(*ans.begin()=='0'&&ans.length()>1){
		ans.erase(ans.begin());
	}
	cout<<ans<<endl;
	
	return 0;
}
