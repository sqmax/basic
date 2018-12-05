#include<cstdio>
#include<cstring>

struct Stu{
	char id[20],signI[20],signO[20];
	
};

int main(){
	int m;
	scanf("%d",&m);
	Stu first,last;
	strcpy(first.signI,"24:00:00");
	strcpy(last.signO,"00:00:00");
//	printf("%s %s\n",first.signI,last.signO);
	for(int i=0;i<m;i++){
		Stu temp;
		scanf("%s %s %s",temp.id,temp.signI,temp.signO);
		if(strcmp(temp.signI,first.signI)<0){
			first=temp;
		}
		if(strcmp(temp.signO,last.signO)>0){
			last=temp;
		}
	}
	printf("%s %s\n",first.id,last.id);
	
	return 0;
}
