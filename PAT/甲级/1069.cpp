#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	int a;
	scanf("%d",&a);
	char str[5];//��������4�ͻ����г���һ��û�У��ð��첻֪�������ġ���ΪC�����ַ������һλҪ��'\0' 
	sprintf(str,"%04d",a);
	while(true){
		sort(str,str+4);
		int a,b;
		sscanf(str,"%04d",&a);
		reverse(str,str+4);
		sscanf(str,"%04d",&b);
		
		printf("%04d - %04d = %04d\n",b,a,b-a);
		
		if(a==b||b-a==6174){	
			break;
		}else{			
			sprintf(str,"%04d",b-a);
		}
	}
	
	return 0;
} 
