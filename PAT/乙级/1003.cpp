#include<cstdio>
#include<cstring> 

char str[110];

int main()
{
	int n;
	scanf("%d",&n);
	while(n--){
		bool flag=true;
		scanf("%s",str);
		int posP=0,posA=0,posT=0;
		int numP=0,numT=0,numA=0;
		for(int i=0;i<strlen(str);i++){
			if(str[i]=='P'){
				posP=i;
				numP++;
			}else if(str[i]=='T'){
				posT=i;
				numT++;
			}else if(str[i]=='A'){
				numA++;
			}else{
				flag=false;
			}			
		}	
		if(posT<posP||numP!=1||numT!=1||numA==0){
			flag=false;
		}
		//printf("%d %d %d\n",flag,posP,posT);
		int x=posP,y=posT-posP-1,z=strlen(str)-1-posT;
		if(x*(y-1)+x!=z){
			flag=false;
		}
		//printf("%d %d %d\n",x,y,z);   
		if(flag==true){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
		 	
	}
	
	return 0;
}
