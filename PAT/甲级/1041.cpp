#include<iostream>
using namespace std;

const int maxn=10010;
int cnt[maxn];

int main(){
	int n;
	cin>>n;
	int num[n];
	for(int i=0;i<n;i++){
		cin>>num[i];
		cnt[num[i]]++;
	}
	int i;
	for(i=0;i<n;i++){
		if(cnt[num[i]]==1){
			cout<<num[i]<<endl;
			break;
		}
	}
	if(i==n) cout<<"None"<<endl;
	
	return 0;
} 
