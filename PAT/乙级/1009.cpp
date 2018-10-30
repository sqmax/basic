#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(){

//	char str[100];
//	scanf("%s",str);
//	
//	int len=strlen(str);
//	printf("%s",str);
//	int i,j;
//	i=j=len-1;
//	while(i>=0){
//		while(i>0&&str[i]!=' '){
//			i--;
//		}
//		for(int k=i+1;k<=j;k++){
//			printf("%c",str[k]);
//		}
//		printf(" ");
//		i--;
//		j=i;
//	}
	string str[100];
	int cnt=0;
	char temp[100];
	while(scanf("%s",temp)!=EOF){
		str[cnt++]=temp;	
	}
	
	while(--cnt>0){
		cout<<str[cnt]<<" ";
	}
	cout<<str[0]<<endl;
	
	return 0;
} 

