/* 
给一棵二叉树，每个结点都有一个水平位
置：左子结点在它左边1个单位，右子结点在右
边1个单位。从左向右输出每个水平位置的所有
结点的权值之和。如图6-7所示，从左到右的3个
位置的权和分别为7，11，3。按照递归（先序）
方式输入，用-1表示空树。
样例输入：
5 7 -1 6 -1 -1 3 -1 -1
8 2 9 -1 -1 6 5 -1 -1 12 -1 -1 3 7 -1 -1 -1
-1
样例输出：
Case 1:
7 11 3
Case 2:
9 7 21 15
 */
#include <bits/Stdc++.h>
using namespace std;
constexpr int maxn = 100;
int sum[maxn];
//输入并统计一棵子树，树根水平位置为p
void build(int p) {
	int v;
	cin >> v;
	if (v == -1)
		return; //空树
	sum[p] += v;
	build(p - 1);
	build(p + 1);
}
//边读入边统计
bool init() {
	int v;
	cin >> v;
	if (v == -1)
		return false;
	memset(sum, 0, sizeof(sum));
	int pos = maxn / 2; //树根的水平位置
	sum[pos] = v;
	build(pos - 1);
	build(pos + 1);
}
int main() {
	int kase = 0;
	while (init()) {
		int p = 0;
		while (sum[p] == 0)
			p++; //找最左边的叶子
		cout << "Case " << ++kase << ":\n"
			 << sum[p++]; //因为要避免行末多余空格
		while (sum[p] != 0)
			cout << " " << sum[p++];
		cout << "\n\n";
	}
	return 0;
}