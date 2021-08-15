#include <bits/stdc++.h>
using namespace std;
vector<pair<string, int>> vpsi;
int main() {
	char ch;
	string str;
	while (scanf("%c", &ch)) {
		if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9' || ch == '_') {
			if (ch >= 'A' && ch <= 'Z')
				ch = ch + 32;
			if (str.size() < 15)
				str += ch;
		}
		else if (str.size() > 0) {
			if (str.size() > 0) {
				int isIn = 0;
				for (int i = 0; i < vpsi.size(); i++) {
					if (vpsi[i].first == str) {
						vpsi[i].second++;
						isIn = 1;
					}
				}
				if (!isIn) {
					vpsi.push_back(make_pair(str, 1));
				}
			}
			str.clear();
		}
		if (ch == '#') {
			break;
		}
	}
	printf("%d\n", vpsi.size());
	sort(vpsi.begin(), vpsi.end(), [](auto& s1, auto& s2) {
		if (s1.second == s2.second)
			return s1.first < s2.first;
		else
			return s1.second > s2.second;
	});
	for (int i = 0; i < vpsi.size() / 10; i++)
		printf("%d:", vpsi[i].second), cout << vpsi[i].first, printf("\n");//good ^_^
}