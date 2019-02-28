#include<cstdio>
#include<iostream>
#include<set>
using namespace std;

int main(){
	int n;
	cin>>n;
	set<int> st[n];
	for(int i=0;i<n;i++){
		int m,a;
		cin>>m;
		for(int j=0;j<m;j++){
			cin>>a;
			st[i].insert(a);
		}
	}
	int k;
	cin>>k;
	while(k--){
		int a,b;
		cin>>a>>b;
		a--,b--;
		int nc=0,nt=st[b].size();
		for(auto i:st[a]){
			if(st[b].find(i)==st[b].end()){
				nt++;
			}else{
				nc++;
			}
		}
		printf("%.1f%\n",nc*100.0/nt);
	}
	
	return 0;
}
