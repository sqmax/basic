#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

bool isLegal(string s,double &f){
	bool ans=true;
	bool flag=true;//表示正号 
	if(s[0]=='-'){//消掉负号，便于处理 
		s.erase(s.begin());
		flag=false;
	}
	if(s.find('.')!=-1&&(s.length()-s.find('.') >3)){//小数位数大于3或在头部或末尾 s.find('.')==0||s.length()-s.find('.')<=1||
		ans=false;
	}
	int pointNum=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='.'){
			pointNum++;
			if(pointNum>1){
				ans=false;
				break;
			}
		}else if(s[i]<'0'||s[i]>'9'){
			ans=false;
			break;
		}
	}
	if(ans==true){
		sscanf(s.c_str(),"%lf",&f);
		if(flag==false) f=-f;
		if(f>1000||f<-1000){
			ans=false;
		}
	}
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	int legalNum=0;
	double sum=0;
	while(n--){
		string str;
		cin>>str; 
		double f;
		if(isLegal(str,f)){
			printf("%.2lf\n",f);
			sum+=f;
			legalNum++;
		}else{
			printf("ERROR: %s is not a legal number\n",str.c_str());
		}
	}
	if(legalNum==0){
		printf("The average of 0 numbers is Undefined\n");
	}else if(legalNum==1){
		printf("The average of 1 number is %.2lf\n",sum);
	}else{
		printf("The averages of %d numbers is %.2lf\n",legalNum,sum/legalNum);
	}
	
	return 0;
}

