/** 
 * 用bool数组的下标表示id
 * 若在朋友圈则下标为true
 */
#include <bits/stdc++.h>
using namespace std;
bool book[100001] = { false };
int main() {
	int n, m, k;
	cin >> n;
	while (n--) {
		cin >> m;
		if (m == 1)
			cin >> k;
		else {
			while (m--) {
				cin >> k;
				book[k] = true;
			}
		}
	}
	cin >> n;
	bool flag = false;
	while (n--) {
		cin >> k;
		if (book[k] == false) {
			if (flag == true)
				cout << " ";
			printf("%05d", k);
			flag = true;
			book[k] = true;
		}
	}
	if (flag == false)
		cout << "No one is handsome";
	return 0;
}