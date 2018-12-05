#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxk=2510;
vector<string> course[maxk];

int main(){
	int n,k;
	cin>>n>>k;
	string name;
	int cNum,cId;
	for(int i=0;i<n;i++){
		cin>>name>>cNum;
		for(int j=0;j<cNum;j++){
			cin>>cId;
			course[cId].push_back(name);
		}
	}
	int size;
	for(int i=1;i<=k;i++){
		cout<<i<<" "<<course[i].size()<<"\n";
		sort(course[i].begin(),course[i].end());
		size=course[i].size();
		for(int j=0;j<size;j++){
			cout<<course[i][j]<<"\n";//刚开始写的是endl，最后一个测试点超时，百思不解，改为"\n"就好了 
		}
	}
	
	return 0;
}
