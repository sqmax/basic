#include<cstdio>
#include<vector>
#include<set>
using namespace std;

const int maxn=210;
int G[maxn][maxn];
int n,m;

//TS simple cycle=1
//Not a TS cycle=2
//TS cycle=3
//NA=4
int check(vector<int> vc,int &dis){
	int tot=0;
	int a=vc[0],b;
	int rnt=1;
	set<int> st;
	st.insert(a);
	for(int i=1;i<vc.size();i++){
		b=vc[i];
		st.insert(b);
		if(G[a][b]){
			tot+=G[a][b];
			a=b;	
		}else{
//			printf("%d%d\n",a,b);
			rnt=4;
			break;
		}
		
	}
	dis=tot;
	if(rnt!=4){
		if(vc.size()>n+1&&st.size()==n){
			rnt=3;
		}else if(st.size()<n||vc.size()==st.size()){
			rnt=2;
		}
		else if(st.size()==n&&vc[0]!=vc[vc.size()-1]){
			rnt=2;
//			printf("hel------%d %d\n",v,*vc.end());
			
		}
		
	}
	return rnt;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b,dis;
		scanf("%d%d%d",&a,&b,&dis);
		G[a][b]=G[b][a]=dis;
	}
	int k;
	scanf("%d",&k);
	int path,shortest=10000;
	for(int i=1;i<=k;i++){
		int N;
		vector<int> vc;
		scanf("%d",&N);
		for(int j=0;j<N;j++){
			int a;
			scanf("%d",&a);
			vc.push_back(a)                                                                                                                                ;
		}		
		int dis=0;
		int flg=check(vc,dis);
		if(flg==2){
			printf("Path %d: %d (Not a TS cycle)\n",i,dis);
		}else if(flg==4){
			printf("Path %d: NA (Not a TS cycle)\n",i);
		}else{
			if(flg==1){
				printf("Path %d: %d (TS simple cycle)\n",i,dis);
			}else if(flg==3){
				printf("Path %d: %d (TS cycle)\n",i,dis);
			}
			if(dis<shortest){
				shortest=dis;
				path=i;
			}
		}
	}
	printf("Shortest Dist(%d) = %d\n",path,shortest);
	
	return 0;
}
