#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<map>
using namespace std;

bool isAlp(char c){
	if((c>='0'&&c<='9')||(c>='a'&&c<='z')) return true;
	else return false;
}
int main(){
//	char s[1048578];
//	gets(s);
	string s;
	getline(cin,s);
	map<string,int> mp;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='A'&&s[i]<='Z'){
			s[i]+=32;
		}
	}
	for(int i=0;i<len;){
		while(i<len&&!isAlp(s[i])){
			i++;
		}
		int j=i;
		string tmp="";
		while(j<len&&isAlp(s[j])){
			tmp+=s[j];
			j++;
		}
		if(mp.find(tmp)==mp.end()){
			mp[tmp]=1;
		}else{
			mp[tmp]++;
		}
		i=j;
	}
	string ans;
	int most=0;
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
		if(it->second>most){
			most=it->second;
			ans=it->first;
		}
	}
	printf("%s %d\n",ans.c_str(),most);
	
	return 0;
}

