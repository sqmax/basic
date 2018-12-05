#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string getDouble(string num){
	string rnt="";
	int over=0;
	for(int i=num.length()-1;i>=0;i--){
		int t=(num[i]-'0')*2+over;
		rnt+=t%10+'0';
		over=t/10;

	}
	if(over) rnt+=over+'0';
	reverse(rnt.begin(),rnt.end());
	return rnt;
}
int main(){
	string num;
	cin>>num;
	string doub=getDouble(num);
	string tmp=doub;
	sort(num.begin(),num.end());
	sort(doub.begin(),doub.end());
	if(num==doub){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	cout<<tmp<<endl;
	
	return 0;
} 
