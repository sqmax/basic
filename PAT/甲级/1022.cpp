#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;

//map<string,set<string> > title;
//map<string,set<string> > author;
//map<string,set<string> > key;
//map<string,set<string> > publisher;
//map<string,set<string> > year;
map<string,set<string> > searchSystem[6];//ֱ�Ӷ���һ��������Ϊ���ݲ�ͬѡ���������������ϵͳ 

void search(int no,string query){
//	if(no==3) return;
	if(searchSystem[no].find(query)==searchSystem[no].end()){
		cout<<"Not Found"<<endl;
		return;
	}
	set<string> ids=searchSystem[no][query];
	
	for(set<string>::iterator it=ids.begin();it!=ids.end();it++){
		cout<<*it<<endl;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	getchar();
	while(n--){
		string id,title,author,key,publisher,year;
		getline(cin,id);
		getline(cin,title);
		getline(cin,author);
//		getline(cin,key);
		while(1){//��һ����Ҫע�⣬���ֱ�Ӷ���һ�У���ת��Ϊstring�����ʱ��ͦ�鷳 
			cin>>key;
//			cout<<key<<endl;
			searchSystem[3][key].insert(id);
			if(getchar()=='\n') break;
		}
		getline(cin,publisher);
		getline(cin,year);

		searchSystem[1][title].insert(id);
		searchSystem[2][author].insert(id);
		
//		searchSystem[3][key].insert(id);

		searchSystem[4][publisher].insert(id);
		searchSystem[5][year].insert(id);
		
	}
	int m;
	scanf("%d",&m);
	getchar();
	while(m--){
		string query;
		getline(cin,query);
		cout<<query<<endl;
		int no=query[0]-'0';
		query=query.substr(3);
		search(no,query);
	}
	return 0;
} 
