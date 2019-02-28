#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=100010;
int a[maxn];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}		
	sort(a,a+n);
	int e=n;
	while(e){
		int pos=upper_bound(a,a+n,e)-a;
//		cout<<pos<<endl;
		int days=n-pos;
		if(days>=e) break; //days>=e，不是days>e 
		e--;
	}
	printf("%d\n",e);
	
	return 0;
}
/*
法二：
#include <iostream>
#include <algorithm>
using namespace std;
int a[1000000];
int main() {
    int n, e = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a+n, greater<int>());
//    printf("%d\n",a[0]);
    while(e < n && a[e] > e+1) e++;
    printf("%d", e);
    return 0;
}
*/ 
