#include<cstdio>
#include<string>
using namespace std;

int longestSubstringWithReplication(const string& str){
	int curLen=0;
	int maxLen=0;
	int* position=new int[26];
	for(int i=0;i<26;i++){
		position[i]=-1;
	}	
	for(int i=0;i<str.length();i++){
		int preIdx=position[str[i]-'a'];
		
		if(preIdx<0||i-preIdx>curLen){
			curLen++;
		}else{
			curLen=i-preIdx;
		}
		position[str[i]-'a']=i;
		
		if(curLen>maxLen){
			maxLen=curLen;
		}
	}
	delete[] position;
	
	return maxLen;
}
int main(){
	int maxL=longestSubstringWithReplication("arabcacfr");
	
	printf("%d\n",maxL);
	return 0;
} 
