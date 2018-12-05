//Ò»¸ö²âÊÔµã´íÎó 
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
	int k;
	bool broken['s'+1];
	fill(broken,broken+'s'+1,true);
	scanf("%d",&k);
	char str[1010];
	scanf("%s",str);
	for(int i=0;i<strlen(str);){
		int j=i;
		while(j<strlen(str)&&str[j]==str[i]){
			j++;
		}
		if((j-i)%k!=0){
			broken[str[i]]=false;
		}
		i=j;
	}
	bool printed['z'+1];
	fill(printed,printed+'z'+1,false);
	bool flag=false;
	for(int i=0;i<strlen(str);i++){
		if(broken[str[i]]==true&&printed[str[i]]==false){
			printf("%c",str[i]);
			printed[str[i]]=true;
			flag=true;
		}
	}
	if(flag==true) printf("\n");

	for(int i=0;i<strlen(str);){
		printf("%c",str[i]);
		if(broken[str[i]]){
			i+=k;
		}else{
			i++;
		}
	}
	
	return 0;
} 
