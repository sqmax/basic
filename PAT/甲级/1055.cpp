#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int maxn=100010;
struct Person{
	string name;
	int age,worth;
}per[maxn],validPer[maxn];
int ageCnt[210];

bool cmp(Person a,Person b){
	if(a.worth!=b.worth) return a.worth>b.worth;
	else if(a.age!=b.age) return a.age<b.age;
	else return a.name<b.name;
}
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>per[i].name>>per[i].age>>per[i].worth;
	}
	sort(per,per+n,cmp);
	int validNum=0;
	for(int i=0;i<n;i++){
		int age=per[i].age;
		if(ageCnt[age]<100){//过滤掉每个年龄100名之外的人，否则第二个测试点超时 
			ageCnt[age]++;
			validPer[validNum++]=per[i];
		}
	}
	for(int i=1;i<=k;i++){
		int m,minA,maxA;
		cin>>m>>minA>>maxA;
		cout<<"Case #"<<i<<":"<<"\n";
		int printCnt=0;
		for(int j=0;j<validNum&&printCnt<m;j++){
			if(validPer[j].age>=minA&&validPer[j].age<=maxA){
				cout<<validPer[j].name<<" "<<validPer[j].age<<" "<<validPer[j].worth<<endl;
				printCnt++;
			}
		}
		if(printCnt==0){
			cout<<"None\n";
		}
	}
	
	return 0;
}
