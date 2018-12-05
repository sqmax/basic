#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string getSum(string a,string b){
	int len1=a.length(),len2=b.length();
	int i=len1-1,j=len2-1;
	string rnt;
	int over=0;
	while(i>=0&&j>=0){
		int t=a[i]-'0'+b[i]-'0'+over;
		rnt+=t%10+'0';
		over=t/10;
		i--,j--;
	}
	while(i>=0){
		rnt+=a[i--]+over;
		over=0;
	}
	while(j>=0){
		rnt+=b[j--];
	}
	if(over) rnt+=over+'0';
	reverse(rnt.begin(),rnt.end());
//	cout<<rnt<<endl;
	return rnt;
}
bool isPalin(string a){
	int len=a.length();
	for(int i=0;i<len/2;i++){
		if(a[i]!=a[len-1-i]) return false;
	}
	return true;
}
int main(){
	string n;
	int k;
	cin>>n>>k;
	int cnt=0;
	while(true){
		if(isPalin(n)){
			break;
		}
		string rev=n;
		reverse(rev.begin(),rev.end());
		n=getSum(n,rev);
		cnt++;
		if(cnt==k){
			break;
		}
	}
	cout<<n<<endl;
	cout<<cnt<<endl;
}
