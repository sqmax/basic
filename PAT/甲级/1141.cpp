#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector> 
using namespace std;

struct Institu{
	string code;
	int tws,person;
}; 
unordered_map<string,Institu> mp;
string toLower(string id){
	for(int i=0;i<id.length();i++){
		if(id[i]>='A'&&id[i]<='Z'){
			id[i]+=32;
		}
	}
	return id;
}
bool cmp(Institu a,Institu b){
	if(a.tws!=b.tws) return a.tws>b.tws;
	else if(a.person!=b.person) return a.person<b.person;
	else return a.code<b.code;
}
int main(){
	int n;
	unordered_map<string,double> sumSco;
	unordered_map<string,int> numPer;
	cin>>n;
	for(int i=0;i<n;i++){
		string id,insti;
		double s;
		cin>>id>>s>>insti;
		insti=toLower(insti);
		
		if(id[0]=='B') s=s/1.5;
		else if(id[0]=='T') s=s*1.5;
//		cout<<insti<<" "<<s<<endl;
		sumSco[insti]+=s;
		numPer[insti]++; 

	}
	vector<Institu> ans;
	for( auto it=numPer.begin();it!=numPer.end();it++){
		ans.push_back(Institu{it->first,(int)sumSco[it->first],numPer[it->first]});
	}
	sort(ans.begin(),ans.end(),cmp);
	printf("%d\n",ans.size());
	int rank=1;
	for(int i=0;i<ans.size();i++){
		if(i==0){
			cout<<rank;
		}else if(ans[i].tws==ans[i-1].tws){
			cout<<rank;
		}else{
			rank=i+1;
			cout<<rank;
		}
		cout<<" "<<ans[i].code<<" "<<ans[i].tws<<" "<<ans[i].person<<"\n";
	}
	return 0;
}

