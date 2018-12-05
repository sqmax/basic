#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=1010;
vector<int> initial,sorted;
int n;

bool insertionSort(){
	vector<int> temp=initial;
	bool flag=false;
	for(int i=1;i<n;i++){
		int j=i-1,tmp=temp[i];
		while(j>=0&&temp[j]>tmp){
			temp[j+1]=temp[j];
			j--;
		}
		temp[j+1]=tmp;
		if(flag==true){
			break;
		}
		if(temp==sorted){
			flag=true;
		}
	}
	if(flag==true){
		printf("Insertion Sort\n");
		for(int i=0;i<temp.size();i++){
			printf("%d",temp[i]);
			if(i<temp.size()-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	return flag;
}
void mergeSort(){
	vector<int> temp=initial;
	bool flag=false;
	for(int step=2;step<n;step*=2){
		for(int i=0;i<n;i+=step){
			sort(temp.begin()+i,temp.begin()+min(n,i+step));
		}
		if(flag==true){
			break;
		}
		if(sorted==temp){
			flag=true;
		}
	}
	if(flag==true){
		printf("Merge Sort\n");
		for(int i=0;i<temp.size();i++){
			printf("%d",temp[i]);
			if(i<temp.size()-1){
				printf(" ");
			}
		}
		printf("\n");
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		initial.push_back(a);
	}
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		sorted.push_back(a);
	}
	if(insertionSort()==false){
		mergeSort();
	} 
	return 0;
}
