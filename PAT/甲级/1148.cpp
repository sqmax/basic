#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

bool cmp(vector<int> a,vector<int> b){
	if(a[0]!=b[0]) return a[0]<b[0];
	else return a[1]<b[1];
}
int main(){
	int n;
	cin>>n;
	int w[n];
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}	
	vector<vector<int> > ans;
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){//¼ÙÉèi,jÎªÆ­×Ó 
			w[i]=-w[i];
			w[j]=-w[j];
			vector<int> liar;
			liar.push_back(i);
			liar.push_back(j);
			set<int> tmpWF;
			for(int k=1;k<=n;k++){
				if(w[k]<0) tmpWF.insert(-w[k]);
			}
			vector<int> wf;
			if(tmpWF.size()==2){
				for(auto i:tmpWF){
					wf.push_back(i);
				}
			}
			cout<<wf.size()<<endl;
			if(wf.size()==2){
				if(liar!=wf){
					if(liar[0]==wf[0]||liar[0]==wf[1]||liar[1]==wf[0]||liar[1]==wf[1]){
						printf("liar:%d %d\n",liar[0],liar[1]);
						ans.push_back(wf);	
					}
				}	
			}
			w[i]=-w[i];
			w[j]=-w[j];	
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i][0]<<" "<<ans[i][1]<<"\n"; 	
	}
	
} 
