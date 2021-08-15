#include <bits/stdc++.h>
#define N 1001
using namespace std;
int a[N];
int idx = 0;
char c;
int main() {
	while (1) {
		scanf("%d", a + idx++);
		scanf("%c", &c);
		if (c != ' ')
			break;
	}
	for (int i = 0; i < idx; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}