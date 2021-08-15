#include <bits/stdc++.h>
using namespace std;
struct Student {
	string name;
	vector<int> c; //curriculum
};
int main(int argc, char const* argv[]) {
	int n, k;
	cin >> n >> k;
	vector<Student> v(n);
	int cnt;
	int c;
	for (size_t i = 0; i < n; i++) {
		cin >> v[i].name;
		cin >> cnt;
		while (cnt--) {
			cin >> c;
			v[i].c.push_back(c);
		}
	}
	sort(v.begin(), v.end(), [](auto& a, auto& b) {
		return a.name < b.name ? 1 : 0;
	});
	vector<vector<string>> vs(k + 1);
	for (auto&& j : v) {
		for (auto&& l : j.c) {
			vs[l].push_back(j.name);
		}
	}
	bool isf = true;
	for (int i = 1; i < vs.size(); ++i) {
		if (isf) {
			cout << i << " " << vs[i].size();
			isf = false;
		}
		else
			cout << "\n"
				 << i << " " << vs[i].size();
		for (auto&& j : vs[i])
			cout << "\n"
				 << j;
	}

	return 0;
}
