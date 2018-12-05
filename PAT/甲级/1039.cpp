#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

const int maxn=1010;
map<string,vector<int> > selCourOfStu;
int main(){
	int n,k;
	cin>>n>>k;
	string name;
	for(int i=1;i<=k;i++){
		int course,numStu;
		cin>>course>>numStu;
		for(int j=0;j<numStu;j++){
			cin>>name;
			selCourOfStu[name].push_back(course);
		}
	}
	for(int i=0;i<n;i++){
		cin>>name;
		vector<int> cour=selCourOfStu[name];
		sort(cour.begin(),cour.end());
		cout<<name<<" "<<cour.size();
		for(int j=0;j<cour.size();j++){
			cout<<" "<<cour[j];
		}
		cout<<"\n";
	}
	return 0;
}
