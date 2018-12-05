#include<cstdio>
#include<map>
#include<set>
using namespace std;

const int maxn=10010;
struct Family{
	int id,memNum;
	double estat,area;
};
int father[maxn];
int findFather(int x){
	int s=x;
	while(father[x]!=x){
		x=father[x];
	}
	//Â·¾¶Ñ¹Ëõ 
	while(father[s]!=x){
		int tmp=father[s];
		father[s]=x;
		s=tmp;
	}
	return x; 
}
void union(int a,int b){
	if(a<0||b<0) return;
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA<faB){
		father[faB]=faA;
	}else if(faA>faB){
		father[faA]=faB;
	}
}
bool cmp(Family a,Family b){
	if(a.area!=b.area){
		return a.area>b.area;
	}else{
		return a.id<b.id;
	}
}
void init(){
	for(int i=0;i<maxn;i++){
		father[i]=i;
	} 
}
int main(){
	int n;
	scanf("%d",&n);
	init();
	map<int,int> estate,area,member;
	set<int> people; 
	while(n--){
		int id,father,mother,k,mEst,area;
		int child[k];
		scanf("%d%d%d%d",&id,&father,&mother,&k);
		union(id,father);
		union(id,mother);
		people.insert(father);
		people.insert(mother);
		for(int i=0;i<k;i++){
			scanf("%d",&child[i]);
			union(id,child[i]);
			people.insert(child[i]);
		}
		int fa=findFather(id);
		scanf("%d%d",&mEst,&area);
		estate[id]=mEst;
		area[id]=area;
//		if(estate.find(fa)==estate.end()){
//			estate[fa]=mEst;
//		}else{
//			estate[fa]+=mEst;
//		}
//		if(area.find(fa)==area.end()){
//			area[fa]=area;
//		}else{
//			area[fa]+=area;
//		}
	}
	int family=0;
	set<int> familyRoot;
	map<int,int> familyEst,familyArea;
	for(set<int>::iterator it=people.begin();it!=people.end();it++){
		int fa=findFather(*it);
		familyEst[fa]+=estate[*it];
		familyArea[fa]+=area[*it];
		if(fa==*it){
			family++;
		}
		if(member.find(fa)==member.end()){
			member[fa]=1;
		}else{
			member[fa]++;
		}
		familyRoot.insert(fa);
	}
	Family ans[family];
	int cnt=0;
	for(set<int>::iterator it=familyRoot.begin();it!=familyRoot.end();it++){
		Family family;
		family.id=*it;
		family.memNum=member[id];
		family.estat=estate[*it];
		family.area=area[*it];
		ans[cnt++]=family;
	}
	sort(ans,ans+cnt,cmp);
	printf("%d\n",family);
	for(int i=0;i<cnt;i++){
		printf("%04d %d %.3lf %.3lf\n",ans[i].id,ans[i].memNum,ans[i].estat,ans[i].area);
	}
	
	return 0;
} 
