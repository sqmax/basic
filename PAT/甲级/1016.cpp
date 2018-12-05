//感觉方法很对也不知道为什么四个测试点全部内存超限，求助！ 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int maxn=1010;
struct Record{
	string name,time;
	int state; 
}record[maxn];
struct Person{
	Record rec[maxn];
}person[maxn];
int unit[24]={10,10, 10, 10, 10, 10, 20, 20, 20, 15, 15, 15, 15, 15, 15, 15, 20, 30, 20, 15, 15, 10, 10, 10};
bool cmp(Record a,Record b){
	if(a.name!=b.name) return a.name<b.name;
	else if(a.time!=b.time) return a.time<b.time;
	else a.state<b.state;
}
double getCostAndTime(string a,string b,int &time){
	int rnt=0;
	int d1=(a[0]-'0')*10+(a[1]-'0'),h1=(a[3]-'0')*10+(a[4]-'0'),m1=(a[6]-'0')*10+(a[7]-'0');
	int d2=(b[0]-'0')*10+(b[1]-'0'),h2=(b[3]-'0')*10+(b[4]-'0'),m2=(b[6]-'0')*10+(b[7]-'0');
	while(d1<d2||(d1==d2&&h1<h2)||(d1==d2&&h1==h2&&m1<m2)){
		rnt+=unit[h1];
		time++;
		m1++;
		if(m1==60){
			m1=0;
			h1++;
		}
		if(h1==24){
			h1=0;
			d1++;
		}
	}
//	while(h1<h2||(h1==h2&&m1<m2)){
//		rnt+=unit[h1];
//		m1++;
//		if(m1==60){
//			m1=0;
//			h1++;
//		}
//	}
	return rnt*0.01;
}
int main(){
	for(int i=0;i<24;i++){
		cin>>unit[i];
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string state;
		cin>>record[i].name>>record[i].time>>state;
		if(state=="on-line"){
			record[i].state=0;
		}else{
			record[i].state=1;
		}
		record[i].time.erase(record[i].time.begin(),record[i].time.begin()+3);
	}
	sort(record,record+n,cmp);
	cout<<"-----------"<<endl;
	string month;
	month+=record[0].time[0];
	month+=record[0].time[1];
	for(int i=0;i<n;i++){
		cout<<record[i].name<<" "<<record[i].time<<" "<<record[i].state<<endl;
	}
	for(int i=0;i<n;){
		int j=i+1;
		while(j<n&&record[j].name==record[i].name){
			j++;
		}
		if(j>i+1){
			double total=0,cost;
			cout<<record[i].name<<" "<<month<<"\n";
			while(i+1<j){
				if(record[i].state==0&&record[i+1].state==1){
					 cout<<record[i].time<<" "<<record[i+1].time;
					 int time=0;
					 cost=getCostAndTime(record[i].time,record[i+1].time,time);
					 printf(" %d $%.2f\n",time,cost);
					 total+=cost;
					 i+=2;
				}else{
					i++;
				}
			}	
			printf("Total amount: $%.2f\n",total);
		}
		i=j;
	}
	
	return 0;
} 
