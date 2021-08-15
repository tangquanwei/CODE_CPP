#include <bits/stdc++.h>
using namespace std;

int main() {
	double n1, n2;
	stack<double> sd;
	string s;
	getline(cin, s);
	reverse(s.begin(), s.end());
	stringstream ss(s);
	// stringstream ss("4 8 / 4 7 - 3 * 2 + +");
	while (ss >> s) {
		switch (s[0]) {
		case '+':
			n1 = sd.top();
			sd.pop();
			n2 = sd.top();
			sd.pop();
			sd.push(n1 + n2);
			break;
		case '-':
			n1 = sd.top();
			sd.pop();
			n2 = sd.top();
			sd.pop();
			sd.push(n1 - n2);
			break;
		case '*':
			n1 = sd.top();
			sd.pop();
			n2 = sd.top();
			sd.pop();
			sd.push(n1 * n2);
			break;
		case '/':
			n1 = sd.top();
			sd.pop();
			n2 = sd.top();
			if (fabs(n2 - 0.0) < 0.0000001) {
				printf("ERROR");
				exit(0);
			}
			sd.pop();
			sd.push(n1 / n2);
			break;
		default:
			sd.push(atof(s.data()));
			break;
		}
	}
	printf("%.1f", sd.top());
	return 0;
}