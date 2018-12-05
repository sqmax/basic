#include<iostream>
#include<string>
using namespace std;

const int maxn=1010;
struct Student{
	string name,pwd;
}stu[maxn];

bool needChange(string &pwd){
	bool flg=false;
	for(int i=0;i<pwd.length();i++){
		switch(pwd[i]){
			case '1':pwd[i]='@';flg=true;break;
			case '0':pwd[i]='%';flg=true;break;
			case 'l':pwd[i]='L';flg=true;break;
			case 'O':pwd[i]='o';flg=true;
		}
	}
	return flg;
}
int main(){
	int n,m=0;
	cin>>n;
	for(int i=0;i<n;i++){
		string name,pwd;
		cin>>name>>pwd;
		if(needChange(pwd)){
			stu[m].name=name;
			stu[m++].pwd=pwd;
		}
	}
	
	if(m==0){
		if(n==1) cout<<"There is 1 account and no account is modified"<<endl;
		else if(n>1) cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
	}else{
		cout<<m<<endl;
		for(int i=0;i<m;i++){
			cout<<stu[i].name<<" "<<stu[i].pwd<<endl;
		}	
	}
	
	return 0;
}
