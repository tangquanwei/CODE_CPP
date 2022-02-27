#include <bits/stdc++.h>
using namespace std;

/* 尾递归: 每个函数末尾只使用一个递归调用(递归调用是最后一句) */
void tail(int i) {
	if (i > 0) {
		cout << i << ' ';
		tail(i - 1);
	}
}
/* 尾递归很容易用循环代替 */
void loop(int i) {
	while (i--)
		cout << i + 1 << ' ';
}

/* 非尾递归 转化为迭代形势需要显示的调用栈 */
void reverse() {
	char ch;
	cin.get(ch);
	if (ch != '\n')
		reverse();
	cout.put(ch);
}
void simpleIterativeReverse() {
	char stack[80];
	register int top = 0;
	cin.getline(stack, 80);
	for (top = strlen(stack) - 1; top >= 0; cout.put(stack[top--]))
		;
}
void iterativeReverse() {
	char stack[80];
	register int top = 0;
	cin.get(stack[top]);
	while (stack[top] != '\n')
		cin.get(stack[++top]);
	for (top--; top >= 0; cout.put(stack[top--]))
		;
}
int main(int argc, char const* argv[]) {
	// tail(18);
	// cout << endl;
	// loop(18);
	// reverse();
	// simpleIterativeReverse();
	iterativeReverse();
	return 0;
}
