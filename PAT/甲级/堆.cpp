#include<cstdio>
#include<algorithm> 
using namespace std;

const int maxn=100;
int heap[maxn],n=10;

//���µ��� 
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
//���� 
void createHeap(){
	for(int i=n/2;i>=1;i--){
		downAdjust(i,n);
	}
} 
//ɾ���Ѷ�Ԫ��
void deleteTop(){
	heap[1]=heap[n--];
	downAdjust(1,n);
} 

//���Ҫ���������һ��Ԫ�أ����԰���Ҫ��ӵ�Ԫ�ط����������
//Ȼ��������µ������������µ����������ǰ��������ڵ��븸�ڵ�Ƚ�
//�����Ȩֵ�ȸ��ڵ����ô�ͽ������븸�ڵ㣬���������Ƚϣ�
//ֱ������Ѷ����߸��ڵ��Ȩֵ�ϴ�Ϊֹ��ʱ�临�Ӷ�ΪO(logn);
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
//���Ԫ�� 
void insert(int x){
	heap[++n]=x;
	upAdjust(1,n);
} 
 
//������
//�ѽṹ��ָʹ��һ���ѽṹ��һ�����н������򡣴˴����۵�����������
void heapSort(){
	createHeap();//���ѣ��󶥶ѣ�
	for(int i=n;i>1;i--){
		swap(heap[i],heap[1]);
		downAdjust(1,i-1);
	} 
} 
int main(){
	
	return 0;
}
