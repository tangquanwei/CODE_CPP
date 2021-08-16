#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m, temp, size = 0;
	scanf("%d%d", &n, &m);
	int heap[n + 1];
	heap[0] = -65535;
	while (n--) {
		scanf("%d", &temp);
		int i;
		for (i = ++size; temp < heap[i / 2]; i /= 2)
			heap[i] = heap[i / 2]; //父节点下移
		heap[i] = temp;
	}
	while (m--) {
		scanf("%d", &temp);
		printf("%d", heap[temp]);
		while (temp > 1) {
			temp /= 2;
			printf(" %d", heap[temp]);
		}
		if (m != 0)
			printf("\n");
	}
    return 0;
}
