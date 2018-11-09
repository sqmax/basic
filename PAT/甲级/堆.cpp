#include<cstdio>
#include<algorithm> 
using namespace std;

const int maxn=100;
int heap[maxn],n=10;

//向下调整 
void downAdjust(int low,int high){
	int i=low,j=i*2;
	while(j<=high){
		if(j+1<=high&&heap[j+1]>heap[j]){
			j=j+1;
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
//建堆 
void createHeap(){
	for(int i=n/2;i>=1;i--){
		downAdjust(i,n);
	}
} 
//删除堆顶元素
void deleteTop(){
	heap[1]=heap[n--];
	downAdjust(1,n);
} 

//如果要往堆里添加一个元素，可以把想要添加的元素放在数组最后，
//然后进行向下调整操作。向下调整操作总是把欲调整节点与父节点比较
//，如果权值比父节点大，那么就交换其与父节点，这样反复比较，
//直到到达堆顶或者父节点的权值较大为止。时间复杂度为O(logn);
void upAdjust(int low,int high){
	int i=high,j=i/2;
	while(j>=low){
		if(heap[j]<heap[i]){
			swap(heap[j],heap[i]);
			i=j;
			j=i/2;
		}else{
			break;
		}
	}
}
//添加元素 
void insert(int x){
	heap[++n]=x;
	upAdjust(1,n);
} 
 
//堆排序
//堆结构是指使用一个堆结构对一个序列进行排序。此处讨论递增排序的情况
void heapSort(){
	createHeap();//建堆（大顶堆）
	for(int i=n;i>1;i--){
		swap(heap[i],heap[1]);
		downAdjust(1,i-1);
	} 
} 
int main(){
	
	return 0;
}
