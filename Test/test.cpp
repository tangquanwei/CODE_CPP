#include <bits/stdc++.h>
#define max 1005
#define min -10001
using namespace std;

int h[max], size;
void Insert(int temp) {
	int i;
	for (i = ++size; h[i / 2] > temp; i /= 2) 
		h[i] = h[i / 2];//小顶堆，如果父节点大于插入结点则二者交换
	h[i] = temp;
}
int main() {
	int n, m;
	int temp;
	int i, j;
	scanf("%d %d", &n, &m);
	size = 0;
	h[0] = min;
	for (i = 0; i < n; i++) {
		scanf("%d", &temp);
		Insert(temp);
	}
	for (i = 0; i < m; i++) {
		scanf("%d", &j);
		printf("%d", h[j]);
		while (j > 1) {
			j /= 2;
			printf(" %d", h[j]);
		}
		printf("\n");
	}
	return 0;
}
