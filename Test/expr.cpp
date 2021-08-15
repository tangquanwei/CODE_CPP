#include <bits/stdc++.h>
using namespace std;

int main() {
	stack<double> num;
	stack<char> punc;
	string expr;
	cin >> expr;
	int n = expr.length();
	int ans;
	for (int i = 0; i < n; ++i) {
		if (isdigit(expr[i])) {
			num.push(expr[i] - '0');
		}
		else if (expr[i] == ')') {
			int a = num.top();
			num.pop();
			int b = num.top();
			num.pop();
			char ch = punc.top();
			punc.pop();
			switch (ch) {
			case '+':
				num.push(a + b);
				break;
			case '-':
				num.push(a - b);
				break;
			case '*':
				num.push(a * b);
				break;
			case '/':
				num.push(a*1.0 / b);
				break;
			}
		}
		else if (ispunct(expr[i])) {
			punc.push(expr[i]);
		}
	}
	cout << num.top();

	return 0;
}