#include<cstdio>
#include<cstring>

char str[85],typed[85];
bool good['z'+1];
bool collect['z'+1];
char ans[180];

int main(){
	scanf("%s",str);
	scanf("%s",typed);
	for(int i=0;i<strlen(typed);i++){
		char c=typed[i];
		if(c>='a'&&c<='z'){
			c=c-32;
		}
		good[c]=true;
	}	
	int cnt=0;
	for(int i=0;i<strlen(str);i++){
		char c=str[i];
		if(c>='a'&&c<='z'){
			c=c-32;
		}
		if(good[c]==false&&collect[c]==false){
			ans[cnt++]=c;
			collect[c]=true;
		}
	}
	for(int i=0;i<cnt;i++){
		printf("%c",ans[i]);
	}
	
	return 0;
}
