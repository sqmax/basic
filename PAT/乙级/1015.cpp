#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=100010;
struct Student{
	char id[10];
	int de,ca,sum;
	int cla;
}stu[maxn];

bool compare(Student a,Student b){
	if(a.cla!=b.cla){
		return a.cla<b.cla;
	}else if((a.sum)!=(b.sum)){
		return (a.sum)>(b.sum);
	}else if(a.de!=b.de){
		return a.de>b.de;
	}else{
		return strcmp(a.id,b.id)<0;
	}
}
int main(){
	int N,L,H;
	scanf("%d%d%d",&N,&L,&H);
	int cnt=0;
	for(int i=0;i<N;i++){
		char id[10],d,c;
		scanf("%s %d %d",stu[i].id,&stu[i].de,&stu[i].ca);
		stu[i].sum=stu[i].de+stu[i].ca;
//		if(stu[i].de<L||stu[i].ca<L){
//			stu[i].cla=5;
//		}else if(stu[i].de>=H&&stu[i].ca>=H){
//			stu[i].cla=1;
//		}else if(stu[i].de>=H&&stu[i].ca<=H){
//			stu[i].cla=2;
//		}else if(stu[i].de>=stu[i]){
//			stu[i].cla=3;
//		}else{
//			stu[i].cla=4;
//		}
				
		if(stu[i].de>=H&&stu[i].ca>=H){
			stu[i].cla=1;
		}else if(stu[i].ca>=L&&stu[i].de>=H){
			stu[i].cla=2;
		}else if(stu[i].de>=L&&stu[i].ca>=L&&stu[i].de>=stu[i].ca){
			stu[i].cla=3;
		}else if(stu[i].de>=L&&stu[i].ca>=L){
			stu[i].cla=4;
		}else{
			stu[i].cla=5;
		}
		if(stu[i].cla<5){
			cnt++;
		}
		
	}
	sort(stu,stu+N,compare);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		printf("%s %d %d\n",stu[i].id,stu[i].de,stu[i].ca,stu[i].cla);
	}
	return 0;
}	
