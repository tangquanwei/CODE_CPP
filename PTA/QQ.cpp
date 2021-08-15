#include <bits/stdc++.h>
#include <map>
using namespace std;
int main() {
	map<string, string> mp;//挑选合适的数据结构
	string id, password;
	char ch;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {//online
		cin >> ch >> id >> password;
		if (ch == 'N') {
			if (mp[id] == "") {
				cout << "New: OK\n";
				mp[id] = password;
			}
			else
				cout << "ERROR: Exist\n";
		}
		if (ch == 'L') {
			if (mp[id] == "")
				cout << "ERROR: Not Exist\n";
			else if (mp[id] != password)
				cout << "ERROR: Wrong PW\n";
			else
				cout << "Login: OK\n";
		}
	}
	return 0;
}
