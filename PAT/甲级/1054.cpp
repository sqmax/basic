#include<cstdio>
#include<map>
using namespace std;

const int maxn=0x7fffffff;
//int cnt[maxn];
map<int,int> cnt;

int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int a;
			scanf("%d",&a);
			if(cnt.find(a)==cnt.end()){
				cnt[a]=1;
			}else{
				cnt[a]++;
			}
		}
	}
	int dominant,maxC=0;
	for(map<int,int>::iterator it=cnt.begin();it!=cnt.end();it++){
		if(it->second>maxC){
			maxC=it->second;
			dominant=it->first;
		}
	}
	printf("%d\n",dominant);
	
//	int maxC=0;
//	int dominant;
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			int a;
//			scanf("%d",&a);
////			cnt[a]++;
////			if(cnt[a]>maxC){
////				maxC=cnt[a];
////				dominant=a;
////			}
//		}
//	}
//	printf("%d\n",dominant);
	
	return 0;
}
