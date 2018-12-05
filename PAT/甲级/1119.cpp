#include <cstdio>
#include <vector>
using namespace std;
vector<int> ans;
int *pre, *post, unique = 1;//��ʾΨһ 
 
int findFromPre (int x, int l, int r) {
	for (int i = l; i <= r; i++) {
		if (x == pre[i]) {
			return i;
		}
	}
	return -1;
}
 
void setIn (int preL, int preR, int postL, int postR) {
	if (preL == preR) {
		ans.push_back(pre[preL]);
		return;
	}
	if (pre[preL] == post[postR]) {//���ڵ� 
		int x = findFromPre(post[postR - 1], preL + 1, preR);//��ǰ��������ҵ��������ĸ��ڵ�λ��x������ǰ������иýڵ�֮ǰ������������֮���������� 
		int leftNum=x-preL-1;
		if (leftNum>0) {//����������
			setIn(preL + 1, x - 1, postL, postL + leftNum - 1);//�ݹ�ش����������� 
			ans.push_back(post[postR]);//���ʸ��ڵ� 
			setIn(x, preR, postL + leftNum, postR - 1);//�ݹ�ش����������� 
		} else {
			unique = 0;//���������������������������Ψһ 
			ans.push_back(post[postR]);//���ʸ��ڵ� 
			setIn(x, preR, postL + leftNum, postR - 1);//�ݹ�������������� 
		}
	}
}
 
int main() {
	int n = 0;
	scanf("%d", &n);
	pre = new int [n];
	post = new int [n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	setIn(0, n - 1, 0, n - 1);
	printf("%s\n", unique ? "Yes" : "No");
	printf("%d", ans[0]);
	for (int i = 1; i < ans.size(); i++) {
		printf(" %d", ans[i]);
	}
	printf("\n");
	return 0;
}
