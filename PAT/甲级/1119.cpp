#include <cstdio>
#include <vector>
using namespace std;
vector<int> ans;
int *pre, *post, unique = 1;//表示唯一 
 
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
	if (pre[preL] == post[postR]) {//根节点 
		int x = findFromPre(post[postR - 1], preL + 1, preR);//从前序遍历中找到右子树的根节点位置x，则在前序遍历中该节点之前都是左子树，之后都是右子树 
		int leftNum=x-preL-1;
		if (leftNum>0) {//存在左子树
			setIn(preL + 1, x - 1, postL, postL + leftNum - 1);//递归地从左子树进行 
			ans.push_back(post[postR]);//访问根节点 
			setIn(x, preR, postL + leftNum, postR - 1);//递归地从右子树进行 
		} else {
			unique = 0;//不存在左子树，则构造的右子树不唯一 
			ans.push_back(post[postR]);//访问根节点 
			setIn(x, preR, postL + leftNum, postR - 1);//递归地向右子树进行 
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
