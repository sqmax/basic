#include<cstdio>
#include<cstring>

struct BigN{
	char num[1010];
};
BigN reverse(BigN a){
	BigN rnt;
	int len=strlen(a.num);
	for(int i=0;i<len;i++){
		rnt.num[i]=a.num[len-1-i];
	}
	rnt.num[len]='\0';
	return rnt;
}
BigN add(BigN a,BigN b){
	BigN ans;
	int len=strlen(a.num);
	int i=len-1,j=0;
	int left=0;
	while(i>=0){
		ans.num[j++]=(a.num[i]-'0'+b.num[i]-'0'+left)%10+'0';
		left=(a.num[i]-'0'+b.num[i]-'0'+left)/10;
		i--;
	}
	if(left>0){
		ans.num[j++]=left+'0';
	}
	ans.num[j++]='\0';
	return reverse(ans);
}
bool isPalindromic(BigN a){
	int len=strlen(a.num);
	for(int i=0;i<len;i++){
		if(a.num[i]!=a.num[len-1-i]){
			return false;
		}
	}
	return true;
}
int main(){
	BigN a;
	scanf("%s",a.num);
	int cnt=0;
	if(isPalindromic(a)){
		printf("%s is a palindromic number.\n",a.num);
		return 0;
	}
	while(true){
		BigN b=reverse(a);
		BigN c=add(a,b);
		cnt++;
		printf("%s + %s = %s\n",a.num,b.num,c.num);
		if(isPalindromic(c)){
			printf("%s is a palindromic number.\n",c.num);
			break;
		}
		if(cnt==10){
			printf("Not found in 10 iterations.\n");
			break;
		}
		a=c;
	}
	return 0;
}
