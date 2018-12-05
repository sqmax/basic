//3¸ö²âÊÔµã´íÎó£¬ÇóÖú 
#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=10010;
struct Person{
	string name;
	int height;
}person[maxn];

bool cmp(Person a,Person b){
	if(a.height!=b.height){
		return a.height>b.height;
	}else{
		a.name<b.name;
	}
}
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>person[i].name>>person[i].height;
	}
	sort(person,person+n,cmp);
//	printf("------------\n");
//	for(int i=0;i<n;i++){
//		cout<<person[i].name<<" "<<i<<endl;
//	}
//	printf("------------\n");
	int lastRowNum;
	if(n>k){
		lastRowNum=n%k+k;
	}else{
		lastRowNum=n;
	}
	int row=n/k;
	string line="";
	int cnt=0;
	for(int i=0;i<lastRowNum;i++){
		if(i%2){
			line.insert(0," ");
			line.insert(0,person[i].name);
		}else{
			if(i) line.append(" ");
			line.insert(line.length(),person[i].name);
		}
		cnt++;
	}
	cout<<line<<endl;
	row--;
	while(row>0){
		line="";
		for(int i=0;i<k;i++){
			if(i%2){
				line.insert(0," ");
				line.insert(0,person[cnt].name);
			}else{
				if(i) line.append(" ");
				line.insert(line.length(),person[cnt].name);
			}
			cnt++;
		}
		cout<<line<<endl;
		row--;
	}
	return 0;
}
