#include<cstdio>
#include<vector> 
using namespace std;

const int maxn=1010;
vector<int> initial,sorted;
vector<int> temp;
int n;
bool insertionSort(){
	bool flag=false;
	temp=initial;
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
	return flag;
} 
vector<int> heap;
void downAdjust(int low,int high){
	int i=low,j=i*2;
	while(j<=high){
		if(j+1<high&&heap[j+1]>heap[j]){
			j++;
		}
		if(heap[j]>heap[i]){
			swap(heap[j],heap[i]);
			i=j;
			j=i*2;
		}else{
			break;
		}
	}
}

void createHeap(){
	heap=initial;
	heap.insert(heap.begin(),0);
	for(int i=n/2;i>=1;i--){
		downAdjust(i,n);
	}
}
void heapSort(){
	createHeap();
	bool flag=false;
	sorted.insert(sorted.begin(),0);
	for(int i=n;i>1;i--){
		swap(heap[i],heap[1]);
		downAdjust(1,i-1);
		if(flag==true){
			break;
		}
		if(sorted==heap){
			flag=true;
		}
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
	bool flg=true;
	if(initial==sorted) flg=false;
	if(insertionSort()){
		printf("Insertion Sort\n");
		for(int i=0;i<n;i++){
			printf("%d",temp[i]);
			if(i<n-1) printf(" ");
		}
	}else{
		heapSort();
		printf("Heap Sort\n");
		for(int i=1;i<heap.size();i++){
			printf("%d",heap[i]);
			if(i<heap.size()-1) printf(" "); 
		}
	}
	
} 
