//谁能告诉我哪里错了，为什么，要疯了 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int maxn=110;
const int maxk=310;
struct Student{
	string id;
	int score,location,lRank,fRank; 
}stu[maxn*maxk];

bool cmp(Student a,Student b){
	if(a.score!=b.score) return a.score>b.score;
	else a.id<b.id;
}
int main(){
	int n,k;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>stu[cnt].id>>stu[cnt].score;
			stu[cnt++].location=i;
		}
		sort(stu+cnt-k,stu+cnt,cmp);
		stu[cnt-k].lRank=1;
		for(int j=cnt-k+1;j<cnt;j++){
			if(stu[j].score==stu[j-1].score){
				stu[j].lRank=stu[j-1].lRank;
			}else{
				stu[j].lRank=j-(cnt-k)+1;
			}
		}
	}
	sort(stu,stu+cnt,cmp);
	stu[0].fRank=1;
	for(int i=0;i<cnt;i++){
		if(stu[i].score==stu[i-1].score){
			stu[i].fRank=stu[i-1].fRank;
		}else{
			stu[i].fRank=i+1;
		}
	}
	cout<<cnt<<"\n";
	for(int i=0;i<cnt;i++){
		cout<<stu[i].id<<" "<<stu[i].fRank<<" "<<stu[i].location<<" "<<stu[i].lRank<<"\n";
	}
	
	return 0;
}

