#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int x){
	if(x<=1) return false;
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0) return false;
	}
	return true;
}
int main(){
	int m,n;
	cin>>m>>n;
	while(isPrime(m)==false){
		m++;
	}	
	int data[n];
	for(int i=0;i<n;i++){
		cin>>data[i];
	}
	bool occupied[m];
	fill(occupied,occupied+m,false);
	bool first=true;
	for(int i=0;i<n;i++){
		int pos=data[i]%m;
		bool flg=false;
		if(occupied[pos]==false){
			occupied[pos]=true;
			if(first) first=false;
			else printf(" ");
			printf("%d",pos);
			flg=true;
		}else{
			for(int j=1;j<m;j++){
				pos=(data[i]+j*j)%m;
				if(occupied[pos]==false){
					occupied[pos]=true;
					if(first) first=false;
					else printf(" ");
					printf("%d",pos);
					flg=true;
					break;
				}
			}
		}
		if(flg==false){
			occupied[pos]=true;
			if(first) first=false;
			else printf(" ");
			printf("- ");
		}
	}
	return 0;
} 
