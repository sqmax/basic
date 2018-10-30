#include<cstdio>
#include<cstring>

char Week[7][5]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
	char str[4][61];
	scanf("%s %s %s %s",str[0],str[1],str[2],str[3]);
	int len1=strlen(str[0]),len2=strlen(str[1]),len3=strlen(str[2]),len4=strlen(str[3]);
	
	char week,hour;
	int minute;
	int i;
	for(i=0;i<len1&&i<len2;i++){
		if(str[0][i]>='A'&&str[0][i]<='G'&&str[0][i]==str[1][i]){
			week=str[0][i];
			break;
		}
	}
	i++;
	for(;i<len1&&i<len2;i++){
		if(((str[0][i]>='A'&&str[0][i]<='N')||(str[0][i]>='0'&&str[0][i]<='9'))&&str[0][i]==str[1][i]){
			hour=str[0][i];
			break;
		}
	}
	for(i=0;i<len3&&i<len4;i++){
		if(((str[2][i]>='a'&&str[3][i]<='z')||(str[2][i]>='A'&&str[3][i]<='Z'))&&str[2][i]==str[3][i]){
			minute=i;
			break;
		}
	}
//	printf("%c %c",week,hour);
	printf("%s ",Week[week-'A']);
	if(hour>='A'){
		printf("%02d:",hour-'A'+1+9);
	}else{
		printf("%02d:",hour-'0');
	}
	printf("%02d\n",minute);
}

//3485djDkxh4hhGE
//2984akDfkkkkggEdsb
//
//s&hgsfdk
//d&Hyscvnm
