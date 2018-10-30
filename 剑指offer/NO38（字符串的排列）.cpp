#include<cstdio>

void permutation(char* str,char* begin);

void permutation(char* str){
	if(str==NULL){
		return;
	}
	permutation(str,str);
} 
void permutation(char* str,char* begin){
	if(*begin=='\0'){
		printf("%s\n",str);
	}else{
		for(char* ch=begin;*ch!='\0';ch++){
			char temp=*ch;
			*ch=*begin;
			*begin=temp;
			
			permutation(str,begin+1);
			
			temp=*ch;
			*ch=*begin;
			*begin=temp;
		}
	}
}
int main(){
	char a[]="abc";
	permutation(a);
	return 0;
}
