#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

const int maxn=10010;
struct Record{
	string id,time,status;
}record[maxn];
struct Car{
	string id,inTime,outTime,period;
}car[maxn];
bool cmp(Record a,Record b){
	if(a.id!=b.id){
		return a.id<b.id;
	}else if(a.time!=b.time){
		return a.time<b.time;
	}else{
		return a.status<b.status;
	}
}
bool cmp2(Car a,Car b){
	if(a.period!=b.period){
		return a.period>b.period;
	}else{
		return a.id<b.id;
	}
}
string periodInOut(string a,string b){
	int h,m,s;
	int h1,m1,s1;
	sscanf(a.c_str(),"%d:%d:%d",&h,&m,&s);
	sscanf(b.c_str(),"%d:%d:%d",&h1,&m1,&s1);
	int t=h*3600+m*60+s;
	int t1=h1*3600+m1*60+s1;
	int t2=t1-t;
	int h2,m2,s2;
	h2=t2/3600,m2=t2%3600/60,s2=t2%60;
	char tmp[15];
	sprintf(tmp,"%02d:%02d:%02d",h2,m2,s2);
	string ans(tmp);
	return ans;
}
string addPeriod(string a,string b){
	int h,m,s;
	int h1,m1,s1;
	sscanf(a.c_str(),"%d:%d:%d",&h,&m,&s);
	sscanf(b.c_str(),"%d:%d:%d",&h1,&m1,&s1);
	int t=h*3600+m*60+s;
	int t1=h1*3600+m1*60+s1;
	int t2=t1+t;
	int h2,m2,s2;
	h2=t2/3600,m2=t2%3600/60,s2=t2%60;
	char tmp[15];
	sprintf(tmp,"%02d:%02d:%02d",h2,m2,s2);
	string ans(tmp);
	return ans;
}
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>record[i].id>>record[i].time>>record[i].status;		
	}
	sort(record,record+n,cmp);
	
//	printf("--------------------------\n");
//	for(int i=0;i<n;i++){
//		cout<<record[i].id<<" "<<record[i].time<<" "<<record[i].status<<endl;
//		
//	}
	
	int cnt=0;
	for(int i=0;i<n;){
		if(record[i+1].id==record[i].id){
			if(record[i].status=="in"&&record[i+1].status!=record[i].status){
				car[cnt].id=record[i].id;
				car[cnt].inTime=record[i].time;
				car[cnt].outTime=record[i+1].time;
				car[cnt++].period=periodInOut(car[cnt].inTime,car[cnt].outTime);
				i+=2;
			}else{
				i++;
			}
		}
	}
	
//	for(int i=0;i<cnt;i++){
//		cout<<car[i].id<<" "<<car[i].inTime<<" "<<car[i].outTime<<" "<<car[i].period<<endl;
//	}
	for(int i=0;i<k;i++){
		string time;
		cin>>time;
		int carN=0;
		for(int j=0;j<cnt;j++){
			if(time>=car[j].inTime&&time<car[j].outTime){
				carN++;
			}
		}
		printf("%d\n",carN);
	}
	map<string,string> carTime;
	
	for(int i=0;i<cnt;i++){
		if(carTime.find(car[i].id)!=carTime.end()){
			carTime[car[i].id]=addPeriod(carTime[car[i].id],car[i].period);
		}else{
			carTime[car[i].id]=car[i].period;
		}
	} 
	string longTime="0";
	for(map<string,string>::iterator it=carTime.begin();it!=carTime.end();it++){
//		cout<<it->first<<" "<<it->second<<endl;
		if(it->second>longTime){
			longTime=it->second;
		}
	}

	for(map<string,string>::iterator it=carTime.begin();it!=carTime.end();it++){
		if(it->second==longTime){
			cout<<it->first<<" ";
		}
	}
	cout<<longTime<<endl;
//	sort(car,car+cnt,cmp2);
//	for(int i=0;i<cnt;i++){
//		if(car[i].period==car[0].period){
//			cout<<car[i].id<<" ";
//		}else{
//			break;
//		}
//	}
//	cout<<car[0].period<<endl;
	
	return 0;
}
