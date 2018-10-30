#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


int main()
{

	int n,m;
	scanf("%d %d",&n,&m);
	int a[n];
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}	
	m=m%n;
	int cnt=0;
	for(int i=n-m;i<n;i++){		
		printf("%d",a[i]);
		cnt++;
		if(cnt<n) printf(" ");
	}
	for(int i=0;i<n-m;i++){
		printf("%d",a[i]);
		cnt++;
		if(cnt<n) printf(" ");
	}
	return 0;
 } 
