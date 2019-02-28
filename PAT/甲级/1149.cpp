#include<cstdio>
#include<iostream>
#include<map>
#include<set>
using namespace std;

map<int,set<int> > incom;
int main(){
	int n,m;
	cin>>n>>m;
	while(n--){
		int a,b;
		cin>>a>>b;
		incom[a].insert(b);
		incom[b].insert(a);
	}
	while(m--){
		int k;
		set<int> st;
		cin>>k;
		int a;
		for(int i=0;i<k;i++){
			cin>>a;
			st.insert(a);
		}
		bool flg=true;
		for(auto i:st){
			set<int> tmp=incom[i];
			for(auto j:tmp){
				if(st.find(j)!=st.end()){
					flg=false;
					break;
				}
			}
			if(flg==false) break;
		}
		if(flg) cout<<"Yes\n";
		else cout<<"No\n";
	}
	
	return 0;
} 
