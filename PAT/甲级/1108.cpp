#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;

bool isLegal(string s){
	int n1=0,n2=0,n3=0;
	for(int i=0;i<s.length();i++){
		if(i==0&&s[i]=='-') continue;
		if(s[i]>='0'&&s[i]<='9') continue;
		if(s[i]=='.'){
			n1++;
		}else{
			n2++;
		}
	}
	if(n1==1){
		int decimal=s.length()-s.find('.')-1;
		if(decimal>2) return false;
	}else if(n1>=2){
		return false;
	}
	if(n2) return false;
	
	return true;
}
int main(){
	int n;
	cin>>n;
	double a[n];
	string s;
	int cnt=0;
	double tmp=0,tot=0;
	for(int i=0;i<n;i++){
		cin>>s;
		if(isLegal(s)){
			sscanf(s.c_str(),"%lf",&tmp);
			if(tmp<-1000||tmp>1000){
				printf("ERROR: %s is not a legal number\n",s.c_str());
				continue;
			}
			cnt++;
			tot+=tmp;
		}else{
			printf("ERROR: %s is not a legal number\n",s.c_str());
		}
	}
	if(cnt==0){
		printf("The average of 0 numbers is Undefined\n");
	}else if(cnt==1){
		printf("The average of 1 number is %.2lf\n",tot);
	}else{
		printf("The average of %d numbers is %.2lf\n",cnt,tot/cnt);
	}
	
	return 0;
} 
