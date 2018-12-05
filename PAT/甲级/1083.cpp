#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=1010;
struct Student{
	string name,id;
	int score;
}stu[maxn];
bool cmp(Student a,Student b){
	return a.score>b.score;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>stu[i].name>>stu[i].id>>stu[i].score;
	}
	sort(stu,stu+n,cmp);
	int g1,g2;
	cin>>g1>>g2;
	bool flag=false;
	for(int i=0;i<n;i++){
		if(stu[i].score>=g1&&stu[i].score<=g2){
			cout<<stu[i].name<<" "<<stu[i].id<<endl;
			flag=true;
		}
	}
	if(flag==false){
		cout<<"NONE"<<endl;
	}
	return 0;
}
