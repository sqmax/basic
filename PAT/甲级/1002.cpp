#include<cstdio>
#include<iostream>
using namespace std;

const int maxn=1010;
double poly[maxn];
int main(){
	int k,line=2;
	int maxCoe=-1;
	while(line--){
		cin>>k;
		for(int i=0;i<k;i++){
			int coe;
			double exp;
			cin>>coe>>exp;
			if(coe>maxCoe) maxCoe=coe;
			poly[coe]+=exp;
		}
	}
	int cnt=0;
	for(int i=maxCoe;i>=0;i--){
		if(poly[i]){
			cnt++;
		}
	}
	cout<<cnt;
	for(int i=maxCoe;i>=0;i--){
		if(poly[i]){
			printf(" %d %.1lf",i,poly[i]);
		}
	}
	return 0;
}
