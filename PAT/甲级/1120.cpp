#include<cstdio>
#include<set>
using namespace std;

int getFId(int a){
	int rnt=0;
	while(a){
		rnt+=a%10;
		a/=10;
	}
	return rnt;
}
int main(){
	int n;
	set<int> st;
	scanf("%d",&n);
	while(n--){
		int a;
		scanf("%d",&a);
		int t=getFId(a);
		st.insert(t);
	}
	printf("%d\n",st.size());
	for(set<int>::iterator it=st.begin();it!=st.end();it++){
		printf("%d",*it);
		if(it!=--st.end()){
			printf(" ");
		}
	}
	return 0;
}
