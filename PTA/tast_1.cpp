#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second != b.second)
		return a.second > b.second;
	else
		return a.first < b.first;
}
vector<pair<string, int>> v;
map<string, int> m;
int main() {
	char str[100];
	string word;
	map<string, int>::iterator it;
	int start = 0;
	char ch;
	while (ch = getchar()) {
		if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9' || ch == '_') {
			if (ch >= 'A' && ch <= 'Z')
				ch = ch - 'A' + 'a';
			str[start++] = ch;
		}
		else if (start > 0) {
			if (start >= 15)
				start = 15;
			str[start] = 0;
			start = 0;
			word = str;
			it = m.find(word);
			if (it != m.end()) {
				(it->second)++;
			}
			else {
				m[word] = 1;
			}
		}
		if (ch == '#')
			break;
	}
	for (it = m.begin(); it != m.end(); it++) {
		v.push_back(make_pair(it->first, it->second));
	}
	sort(v.begin(), v.end(), cmp);
	vector<pair<string, int>>::iterator itv;
	cout << v.size() << endl;
	int ans = v.size() / 10;
	for (itv = v.begin(); itv != v.begin() + ans; itv++) {
		cout << itv->second << ":" << itv->first << endl;
	}
	return 0;
}