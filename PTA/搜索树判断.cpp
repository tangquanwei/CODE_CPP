// 7-8 搜索树判断 (25 point(s))
// 对于二叉搜索树，我们规定任一结点的左子树仅包含严格小于该结点的键值，而其右子树包含大于或等于该结点的键值。
// 如果我们交换每个节点的左子树和右子树，得到的树叫做镜像二叉搜索树。
// 
// 现在我们给出一个整数键值序列，请编写程序判断该序列是否为某棵二叉搜索树或某镜像二叉搜索树的前序遍历序列，如果是，则输出对应二叉树的后序遍历序列。
// 
// 输入格式:
// 输入的第一行包含一个正整数N（≤1000），第二行包含N个整数，为给出的整数键值序列，数字间以空格分隔。
// 
// 输出格式:
// 输出的第一行首先给出判断结果，如果输入的序列是某棵二叉搜索树或某镜像二叉搜索树的前序遍历序列，则输出YES，否侧输出NO。
// 如果判断结果是YES，下一行输出对应二叉树的后序遍历序列。数字间以空格分隔，但行尾不能有多余的空格。
//
// 输入样例1:
// 7
// 8 6 5 7 10 8 11
// 结尾无空行
// 输出样例1:
// YES
// 5 7 6 8 11 10 8
// 结尾无空行
// 输入样例2:
// 7
// 8 6 8 5 10 9 11
// 输出样例2:
// NO

/** 
 *  方法: 模拟
 *  用所给前序遍历建树
 * 	树的前序遍历==所给前序遍历 ? YES : NO
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct Node* Tree;
struct Node {
	int data;
	Tree left;
	Tree right;
};
void insert(Tree& t, int x) {
	if (!t) {
		t = (Tree)malloc(sizeof(struct Node));
		t->data = x;
		t->left = t->right = nullptr;
	}
	else {
		if (x < t->data)
			insert(t->left, x);
		else
			insert(t->right, x);
	}
}
constexpr int SIZE = 1000;
int pre[SIZE], post[SIZE], a[SIZE];
int idx = 0;
/* MLR */
void preOrderTraversal(Tree t) {
	if (t) {
		pre[idx++] = t->data;
		preOrderTraversal(t->left);
		preOrderTraversal(t->right);
	}
}
/* LRM */
void postOrderTraversal(Tree t) {
	if (t) {
		postOrderTraversal(t->left);
		postOrderTraversal(t->right);
		post[idx++] = t->data;
	}
}
Tree swap(Tree t) { //镜像树
	if (t) {
		t->left = swap(t->left);
		t->right = swap(t->right);
		Tree temp = t->left;
		t->left = t->right;
		t->right = temp;
	}
	return t;
}

int main() {
	Tree tree = nullptr;
	int n, maybeMirror = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		insert(tree, a[i]);
	}

	preOrderTraversal(tree);
	for (int i = 0; i < idx; ++i) {
		if (a[i] != pre[i]) {
			maybeMirror = 1;
		}
	}
	if (maybeMirror) {
		tree = swap(tree);
		idx = 0;
		preOrderTraversal(tree);
		for (int i = 0; i < idx; ++i) {
			if (a[i] != pre[i]) {
				printf("NO");
				goto lab_no;
			}
		}
	}
	printf("YES\n");
	idx = 0;
	postOrderTraversal(tree);
	for (int i = 0; i < idx - 1; ++i) {
		printf("%d ", post[i]);
	}
	printf("%d", post[idx - 1]);
lab_no:
	return 0;
}