#include <bits/stdc++.h>
using namespace std;
using std::cout;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	assert(n == 6);
	map<string, int> msi;
	map<string,string> prt;
	int arr[m], idx = 0;
	string
	for (int i = 0; i < n + 1; ++i) {
		string line;
		getline(cin, line);
		int cnt = count(line.begin(), line.end(), ' ');
		line.substr(cnt);
		msi[line] = cnt;
	}
	while (m--) {
		string a, b, c, d;
		cin >> a >> b >> b >> c >> b >> d;
		std::cout << a << " " << c << '\n';
		switch (c[0]) {
		case 'c':
			if (msi[a] - msi[d] == 2)
				arr[idx++] = 1;
			else
				arr[idx++] = 0;
			break;
		case 'a':
			if (msi[a] < msi[d])
				arr[idx++] = 1;
			else
				arr[idx++] = 0;
			break;
		case 's':
			if (msi[a] == msi[d])
				arr[idx++] = 1;
			else
				arr[idx++] = 0;
			break;
		case 'p': //
			if (msi[a] - msi[d] == -2)
				arr[idx++] = 1;
			else
				arr[idx++] = 0;
			break;
		case 'd':
			if (msi[a] > msi[d])
				arr[idx++] = 1;
			else
				arr[idx++] = 0;
			break;
		}
	}
	for (int i = 0; i < idx; ++i) {
		cout << (arr[i] ? "True" : "False") << '\n';
	}



	return 0;
}