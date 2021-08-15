#include <bits/stdc++.h>
using namespace std;
stringstream ss;
double f() {
	char c[9];
	ss >> c;
	if (c[1] == '\0') { //可能是运算符，也可能是运算数
		double num1, num2;
		switch (c[0]) {
		case '+':
			return f() + f();
			break;
		case '-':
			return f() - f();
			break;
		case '*':
			return f() * f();
			break;
		case '/':
			num1 = f();
			num2 = f();
			if (fabs(num2 - 0.0) < 0.0000001) {
				printf("ERROR");
				exit(0);
			}
			return num1 / num2;
		}
	}
	return atof(c); //将字符串转浮点数
}
int main() {
	string s;
	getline(cin, s);
	ss << s;
	double result = f();
	printf("%.1lf\n", result);
}