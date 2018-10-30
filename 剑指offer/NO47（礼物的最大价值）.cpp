#include<cstdio>
#include<algorithm>
using namespace std;

int getMaxValue(int* values,int rows,int cols){
	if(values==NULL||rows<=0||cols<=0){
		return 0;
	}
	int** maxValues=new int*[rows];
	//int maxValues[rows][cols];
	for(int i=0;i<rows;i++){
		maxValues[i]=new int[cols];
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			int left=0;
			int up=0;
			if(i>0){
				up=maxValues[i-1][j];
			}
			if(j>0){
				left=maxValues[i][j-1];
			}
			maxValues[i][j]=max(left,up)+values[i*cols+j];
		}
	}
	int maxValue=maxValues[rows-1][cols-1];
	for(int i=0;i<rows;i++){
		delete[] maxValues[i];
	}
	delete[] maxValues;
	return maxValue;
}
int main(){
	
	return 0;
} 
