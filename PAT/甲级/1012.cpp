#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

const int maxn=10010;
struct Student{
	int id;
	int score[4];
	int rank[4];
	int bestRank;
	char bestCourse;
}stu[maxn];

char T[4]={'A','C','M','E'};
int course;
bool cmp(Student a,Student b){
	return a.score[course]>b.score[course];
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&stu[i].id,&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
		stu[i].score[0]=(stu[i].score[1]+stu[i].score[2]+stu[i].score[3])/3;
	}
	for(int i=0;i<4;i++){
		course=i;
		sort(stu,stu+n,cmp);
		stu[0].rank[i]=1;
		for(int j=1;j<n;j++){
			if(stu[j].score[i]==stu[j-1].score[i]){
				stu[j].rank[i]=stu[j-1].rank[i];
			}else{
				stu[j].rank[i]=j+1;
			}
		}
	}
//	for(int i=0;i<n;i++){
//		printf("%d ",stu[i].id);
//		for(int j=0;j<4;j++){
//			printf("%d ",stu[i].rank[j]);
//		}
//		printf("\n");
//	}
	for(int i=0;i<n;i++){
		int bestRank=n+1;
		char bestCourse;
		for(int j=0;j<4;j++){
			if(stu[i].rank[j]<bestRank){
				bestRank=stu[i].rank[j];
				bestCourse=T[j];
			}
		}
		stu[i].bestRank=bestRank;
		stu[i].bestCourse=bestCourse;
	}
	map<int,Student> mp;
	for(int i=0;i<n;i++){
		mp[stu[i].id]=stu[i];
	}
	for(int i=0;i<m;i++){
		int id;
		scanf("%d",&id);
		if(mp.find(id)!=mp.end()){
			printf("%d %c\n",mp[id].bestRank,mp[id].bestCourse);	
		}else{
			printf("N/A\n");
		}	
	}
	
	return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
