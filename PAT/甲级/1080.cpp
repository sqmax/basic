#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn=40010;
const int maxm=110;

struct Student{
	int no;
	int ge,gi,tot;
	int rank;
	int choice[5];
}stu[maxn]; 
int quote[maxm];
vector<int> schoolAdmit[maxm];

bool cmp(Student a,Student b){
	if(a.tot!=b.tot) return a.tot>b.tot;
	else return a.ge>b.ge;
}
bool cmp2(int a,int b){
	return stu[a].no<stu[b].no;
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d",&quote[i]);
	}
	for(int i=0;i<n;i++){
		int ge,gi;
		scanf("%d%d",&stu[i].ge,&stu[i].gi);
		stu[i].tot=stu[i].ge+stu[i].gi;
		stu[i].no=i;
		for(int j=0;j<k;j++){
			scanf("%d",&stu[i].choice[j]);
		}
	}
	sort(stu,stu+n,cmp);
	stu[0].rank=1;
	for(int i=1;i<n;i++){
		if(stu[i].tot==stu[i-1].tot&&stu[i].ge==stu[i-1].ge){
			stu[i].rank=stu[i-1].rank;
		}else{
			stu[i].rank=i+1;
		}
	}
//	printf("-----------\n");
//	for(int i=0;i<m;i++){
//		printf("%d ",quote[i]);
//	}
//	printf("\n");
//	for(int i=0;i<n;i++){
//		printf("rank:%d no:%d %d %d %d",stu[i].rank,stu[i].no,stu[i].tot,stu[i].ge,stu[i].gi);
//		for(int j=0;j<k;j++){
//			printf(" %d",stu[i].choice[j]);
//		}
//		printf("\n");
//	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			int ch=stu[i].choice[j];
			if(quote[ch]>0){
				schoolAdmit[ch].push_back(i);
				quote[ch]--;
				break;
			}else{
				int lastAdStu=schoolAdmit[ch][schoolAdmit[ch].size()-1];
				if(stu[i].rank==stu[lastAdStu].rank){
					schoolAdmit[ch].push_back(i);
					quote[ch]--;
					break;
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		sort(schoolAdmit[i].begin(),schoolAdmit[i].end(),cmp2);
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<schoolAdmit[i].size();j++){
			printf("%d",stu[schoolAdmit[i][j]].no);
			if(j<schoolAdmit[i].size()-1) printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
