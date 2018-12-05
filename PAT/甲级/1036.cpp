#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int maxn=1010;
struct Student{
	string name,id;
	int grade;
}stuM,stuF;

int main(){
	int n;
	cin>>n;
	int highFemale=-1,lowMale=101;
	for(int i=0;i<n;i++){
		string name,gender,id;
		int grade;
		cin>>name>>gender>>id>>grade;
		if(gender=="F"){
			if(grade>highFemale){
				highFemale=grade;
				stuF.name=name;
				stuF.id=id;
			}
		}
		if(gender=="M"){
			if(grade<lowMale){
				lowMale=grade;
				stuM.name=name;
				stuM.id=id;
			}
		}
	}
	if(highFemale==-1) cout<<"Absent"<<endl;
	else cout<<stuF.name<<" "<<stuF.id<<endl;
	
	if(lowMale==101) cout<<"Absent"<<endl;
	else cout<<stuM.name<<" "<<stuM.id<<endl;
	
	if(highFemale==-1||lowMale==101){
		cout<<"NA"<<endl;
	}else{
		cout<<highFemale-lowMale<<endl;
	}
	
	return 0;
}
