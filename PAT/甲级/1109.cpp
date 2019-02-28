#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn=10010;
struct People{
	string name;
	int height;
}stu[maxn];
bool cmp(People a,People b){
	if(a.height!=b.height) return a.height>b.height;
	else return a.name<b.name;
}
int main(){
	int n,k;
	cin>>n>>k;
	string name;
	int h;
	for(int i=0;i<n;i++){
		cin>>stu[i].name>>stu[i].height;
	}
	sort(stu,stu+n,cmp);
//	for(int i=0;i<n;i++){
//		cout<<stu[i].name<<" "<<stu[i].height<<endl;
//	}
//	cout<<"-----\n";
	int m;
	vector<int> line;
	int cnt=0;
	for(int i=0;i<k;i++){
		if(i==0) m=n/k+n%k;
		else m=n/k;
		for(int j=0;j<m;j++){
			if(j%2==0){
				line.push_back(cnt++);
			}else{
				line.insert(line.begin(),cnt++);
			}
		}
		for(int j=0;j<m;j++){
			cout<<stu[line[j]].name;
			if(j<m-1) cout<<" ";
			else cout<<"\n";
		}
		line.clear();
	}	
	return 0;
} 
