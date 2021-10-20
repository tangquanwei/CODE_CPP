#include <bits/stdc++.h>
using namespace std;

int G(int x) {
	int ret = 0;
	while (x) {
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	register int a, b, c, d, n;
	while (t--) {
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
		register int x = 1, xi, g;
		register size_t m = LONG_MAX, f;
		while (x <= n) {
			g = G(x);
			f = a * x * x * g + b * x * x + c * x * g * g + d * x * g;
			if (f < m) {
				m = f;
				xi = x;
			}
			++x;
		}
		printf("%d", m);
	}
	return 0;
}