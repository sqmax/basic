#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<int, bool> arr;
struct node {
    int a, b;
};
bool cmp(node x, node y) {
    return x.a != y.a ? x.a < y.a : x.b < y.b;
}
int main() {
    int n, m, k;
    scanf("%d%d", &n, &m);
    vector<int> v[10000];
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        if (a.length() == b.length()) {//a,b同性别 
            v[abs(stoi(a))].push_back(abs(stoi(b)));
            v[abs(stoi(b))].push_back(abs(stoi(a)));
        }
        arr[abs(stoi(a)) * 10000 + abs(stoi(b))] = arr[abs(stoi(b)) * 10000 + abs(stoi(a))] = true;//a,b为好友关系 
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int c, d;
        cin >> c >> d;
        vector<node> ans;
        for (int j = 0; j < v[abs(c)].size(); j++) {
            for (int k = 0; k < v[abs(d)].size(); k++) {
                if (v[abs(c)][j] == abs(d) || abs(c) == v[abs(d)][k]) continue;
                if (arr[v[abs(c)][j] * 10000 + v[abs(d)][k]] == true)
                    ans.push_back(node{v[abs(c)][j], v[abs(d)][k]});
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", int(ans.size()));
        for(int j = 0; j < ans.size(); j++)
            printf("%04d %04d\n", ans[j].a, ans[j].b);
    }
    return 0;
}



//法2，一个测试点错误 
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

const int maxn=310;
bool gender[maxn];
map<int,int> idToN;
map<int,int> nToId;
int numPerson=0;
int G[maxn][maxn];
int change(int id){
	if(idToN.find(id)!=idToN.end()){
		return idToN[id];
	}else{
		idToN[id]=numPerson;
		nToId[numPerson]=id;
		return numPerson++;
	}
}
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
bool cmp(vector<int> a,vector<int> b){
	if(a[0]!=b[0]) return a[0]<b[0];
	else return a[1]<b[1];
}
int main(){
	int n,m;
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
