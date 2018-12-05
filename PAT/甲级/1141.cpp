//最后一个测试点错误，求助 
#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

const int maxn=100010;
struct School{
	string code;
	int total,num;
	School(){
		total=num=0;
	}
}schools[maxn]; 
map<string,int> schToInt;
int numSchool;
int change(string sch){
	if(schToInt.find(sch)!=schToInt.end()){
		return schToInt[sch];
	}else{
		schToInt[sch]=numSchool;
		return numSchool++;
	}
}
bool cmp(School a,School b){
	if(a.total!=b.total){
		return a.total>b.total;
	}else if(a.num!=b.num){
		return a.num<b.num;
	}else{
		return a.code<b.code;
	}
}
string toLowerCase(string s){
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]<='Z'){
			s[i]+='a'-'A';
		}
	}
	return s;
}
int transferScore(char level,int score){
	switch(level){
		case 'T':score*=1.5;break;
		case 'B':score=1.0*score/1.5;break;
	}
	return (int)score;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		string id,school;
		int score;
		cin>>id>>score>>school;
		school=toLowerCase(school);
//		cout<<id<<" "<<score<<" "<<school<<endl;
		int s=change(school);
		score=transferScore(id[0],score);
		schools[s].code=school;
		schools[s].total+=score;
		schools[s].num++;
	}	
	sort(schools,schools+numSchool,cmp);
	printf("%d\n",numSchool);
	int rank=1;
	for(int i=0;i<numSchool;i++){
		if(i>0&&schools[i].total==schools[i-1].total){
			printf("%d ",rank);
		}else{
			printf("%d ",i+1);
			rank=i+1;
		}
		cout<<schools[i].code<<" "<<schools[i].total<<" "<<schools[i].num<<endl;
	}
	
	return 0;
}
