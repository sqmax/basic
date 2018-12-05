//测试点1错误，求教 
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

const int MAXV=310;
int G[MAXV][MAXV];
int gender[MAXV];
bool vis[MAXV];
int n,m;
map<int,int> idToN;
map<int,int> nToId;
int numPerson=0;

void contact(int a,int b,int &cnt,vector<int> path[]){
	for(int i=0;i<numPerson;i++){
		if(i!=a&&i!=b&&G[a][i]==1&&gender[i]==gender[a]){
			for(int j=0;j<numPerson;j++){
				if(j!=i&&j!=a&&j!=b&&G[j][i]==1&&G[j][b]==1&&gender[j]==gender[b]){					
					path[cnt].push_back(nToId[i]);
					path[cnt].push_back(nToId[j]);
					cnt++;
//					printf("%04d %04d\n",i,j);	
				}
			}
		}
	}
} 
int change(int id){
	if(idToN.find(id)!=idToN.end()){
		return idToN[id];
	}else{
		idToN[id]=numPerson;
		nToId[numPerson]=id;
		return numPerson++;
	}
}
bool cmp(vector<int> a,vector<int> b){
	if(a[0]!=b[0]){
		return a[0]<b[0];
	}else{
		return a[1]<b[1];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int a,b;
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		int A,B;
		if(a>0){
			A=change(a);
			gender[A]=1;//等于1为男，0为女 
		}else{
			A=change(-a);
		}
		if(b>0){
			B=change(b);
			gender[B]=1;
		}else{
			B=change(-b);
		}
		G[A][B]=G[B][A]=1;
	}	
	int k;
	scanf("%d",&k);
	
	for(int i=0;i<k;i++){
		scanf("%d%d",&a,&b);
		vector<int> path[m];
		int cnt=0;
		int A,B;
		if(a<0){
			a=-a; 
		}
		A=change(a);
		if(b<0){
			b=-b;
		}
		B=change(b);
		contact(A,B,cnt,path);
		sort(path,path+cnt,cmp);
		printf("%d\n",cnt);
		for(int i=0;i<cnt;i++){
			printf("%04d %04d\n",path[i][0],path[i][1]);
		}
		
	}
}
