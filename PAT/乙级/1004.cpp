#include<cstdio>

const int maxn=1010;
struct Student{
	char name[11];
	char id[11];
	int grade;
};
Student stu[maxn];

int main(){
	int n;
	scanf("%d",&n);
	
	int maxG=-1,minG=110;
	Student a,b;
	for(int i=0;i<n;i++){
		Student temp;
		scanf("%s %s %d",temp.name,temp.id,&temp.grade);
		if(temp.grade>maxG){
			maxG=temp.grade;
			a=temp;
		}
		if(temp.grade<minG){
			minG=temp.grade;
			b=temp;
		}
	}
	printf("%s %s\n",a.name,a.id);
	printf("%s %s\n",b.name,b.id);
	
	return 0;
}
