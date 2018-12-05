//测试点3错误，不知错在哪 ,后来才发现是avg不小于60，我搞成gf不小于60，考试时错了，细心！细心！ 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<iostream>
using namespace std;

const int maxn=30010;
struct Stu{
	string name;
	int gp,gm,gf;
	int avg;
	int level;
	Stu(){
		gp=gm=gf=avg=-1;
		level=0;
	}
}stu[maxn];
map<string,int> strToInt;
int numPerson=0;
int change(string name){
	if(strToInt.find(name)!=strToInt.end()){
		return strToInt[name];
	}else{
		strToInt[name]=numPerson;
		return numPerson++;
	}
}
int cmp(Stu a,Stu b){
	if(a.level!=b.level){
		return a.level>b.level;
	}else if(a.avg!=b.avg){
		return a.avg>b.avg;
	}else{
		return a.name<b.name;
	}
}

int main(){
	int p,m,n;
	cin>>p>>m>>n;
	string name;
	for(int i=0;i<p;i++){
		cin>>name;
		int a=change(name);
		stu[a].name=name;
		cin>>stu[a].gp;
	}
	for(int i=0;i<m;i++){
		cin>>name;
		int a=change(name);
		stu[a].name=name;
		cin>>stu[a].gm;
	}
	for(int i=0;i<n;i++){
		cin>>name;
		int a=change(name);
		stu[a].name=name;
		cin>>stu[a].gf;
		if(stu[a].gm>stu[a].gf){
			stu[a].avg=(int)(stu[a].gm*0.4+stu[a].gf*0.6+0.5);
		}else{
			stu[a].avg=stu[a].gf;
		}
	}
	for(int i=0;i<numPerson;i++){
		if(stu[i].gp>=200&&stu[i].avg>=60){
			stu[i].level=1;
		}else{
			stu[i].level=-1;
		}		
	}
	sort(stu,stu+numPerson,cmp);
	for(int i=0;i<numPerson;i++){
		if(stu[i].level==1){
			cout<<stu[i].name<<' '<<stu[i].gp<<' '<<stu[i].gm<<' '<<stu[i].gf<<' '<<stu[i].avg<<'\n'; 
		}
	}
	return 0;
} 

//法二
//#include<iostream>
//#include<string>
//#include<map>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//const int maxn=1010;
//struct Student{
//	string name;
//	int gp,gm,gf;
//	int avg;
//	int level;
//	Student(){
//		gp=gm=gf=avg=-1;
//		level=0;
//	}
//};
//map<string,Student> stuM;
//bool cmp(Student a,Student b){
//	if(a.level!=b.level){
//		return a.level>b.level;
//	}else if(a.avg!=b.avg){
//		return a.avg>b.avg;
//	}else{
//		return a.name<b.name;
//	}
//}
//int main(){
//	int p,n,m;
//	cin>>p>>n>>m;
//	string name;
//	int score;
//	for(int i=0;i<p;i++){
//		cin>>name>>score;
//		stuM[name].name=name;
//		stuM[name].gp=score;
//	}
//	for(int i=0;i<n;i++){
//		cin>>name>>score;
//		stuM[name].name=name;
//		stuM[name].gm=score;	
//	}
//	for(int i=0;i<m;i++){
//		cin>>name>>score;
//		stuM[name].name=name;
//		stuM[name].gf=score;
//	}
//	vector<Student> stuL;
//	for(map<string,Student>::iterator it=stuM.begin();it!=stuM.end();it++){
//		Student t=it->second;
//		if(t.gp>=200){
//			if(t.gm>t.gf){
//				t.avg=(int)(t.gm*0.4+t.gf*0.6+0.5);
//			}else{
//				t.avg=t.gf;
//			}
//			if(t.avg>=60){
//				stuL.push_back(t);		
//			}
//			
//		}
//	}
//	sort(stuL.begin(),stuL.end(),cmp);
//	
//	for(int i=0;i<stuL.size();i++){
//		cout<<stuL[i].name<<" "<<stuL[i].gp<<" "<<stuL[i].gm<<" "<<stuL[i].gf<<" "<<stuL[i].avg<<"\n";
//	}
//	
//	return 0;
//} 
