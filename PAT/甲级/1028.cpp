#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int maxn=100010;
struct Student{
	string id,name;
	int score;
}stu[maxn];
int C;
bool cmp(Student a,Student b){
	if(C==1) return a.id<b.id;
	else if(C==2){
		if(a.name!=b.name) return a.name<b.name;
		else return a.id<b.id;
	}else if(C==3){
		if(a.score!=b.score) return a.score<b.score;
		else return a.id<b.id;
	} 
}
int main(){
	int n;
	cin>>n>>C;
	for(int i=0;i<n;i++){
		cin>>stu[i].id>>stu[i].name>>stu[i].score;
	}
	sort(stu,stu+n,cmp);
	for(int i=0;i<n;i++){
		cout<<stu[i].id<<" "<<stu[i].name<<" "<<stu[i].score<<"\n";
		
	}
}
