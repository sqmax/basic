#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;

const int maxm=1010;
string name[maxm];
map<string,bool> mp;

int main(){
	int m,n,s;
	scanf("%d%d%d",&m,&n,&s);
	for(int i=1;i<=m;i++){
		cin>>name[i];		
	} 
	bool flag=false;
	for(int i=s;i<=m;){
		if(mp.find(name[i])==mp.end()){
			cout<<name[i]<<endl;
			mp[name[i]]=true;
			flag=true;
			i+=n;
		}else{
			i++;
		}
	}
	if(flag==false){
		cout<<"Keep going..."<<endl;
	}
	
	return 0;
}
