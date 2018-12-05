//这是一类问题：在线查询。如果在查询过程中元素可能发生改变（如插入、修改和删除），就称为在线查询 
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

const int maxn=100010;
const int sqrN=316;//sqrt(100001)，表示每块内元素的个数 

stack<int> st;
int block[sqrN];
int table[maxn];

void peekMedian(int k){
	int sum=0;
	int idx=0;
	while(sum+block[idx]<k){
		sum+=block[idx++];
	}
	int num=idx*sqrN;
	while(sum+table[num]<k){
		sum+=table[num++];
	}
	printf("%d\n",num);
} 
void push(int x){
	st.push(x);
	block[x/sqrN]++;
	table[x]++;
}
void pop(){
	int x=st.top();
	st.pop();
	block[x/sqrN]--;
	table[x]--;
	printf("%d\n",x);
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		char a[15];
		scanf("%s",a);
		if(a[1]=='o'){
			if(st.empty()) printf("Invalid\n");
			else pop();
		}else if(a[1]=='u'){
			int key;
			scanf("%d",&key);
			push(key);
		}else{
			if(st.empty()) printf("Invalid\n");
			else{
				int k;
				if(st.size()%2==0){
					k=st.size()/2;
				}else{
					k=(st.size()+1)/2;
				}
				peekMedian(k);	
			}
			
		}
	}
	
	return 0;
}
//#include<stack>
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//using namespace std;
//
//int main(){
//	ios::sync_with_stdio(true);
//	cin.tie(0);
//	int n;
//	cin>>n;
//	stack<char> st;
//	getchar();
////	priority_queue<char,vector<char>,less<int> > q;
//	while(n--){
//		string s;
//		getline(cin,s);
//		if(s[1]=='u'){
//			st.push(s[5]);
//		}else if(s[1]=='o'){
//			if(!st.empty()){
//				char top=st.top();
//				st.pop();
//				cout<<top<<endl;
//			}else{
//				cout<<"Invalid"<<endl;
//			}
//		}else if(s[1]='e'){
//			if(!st.empty()){
//				stack<char> tmpS=st;
//				vector<char> tmpV;	
//				while(!tmpS.empty()){
//					char top=tmpS.top();
//					tmpS.pop();
//					tmpV.push_back(top);
//				}
//				sort(tmpV.begin(),tmpV.end());
//				int mid=tmpV.size()/2;
//				if(tmpV.size()%2==0) mid-=1;
//				cout<<tmpV[mid]<<endl;
//			}else{
//				cout<<"Invalid"<<endl;
//			}
//		}
//	}
//	return 0;
//} 
