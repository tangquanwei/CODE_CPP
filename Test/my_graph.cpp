#include <bits/stdc++.h>
using namespace std;
constexpr int SIZE = 100;
typedef int weight_t;
typedef weight_t** graph;

weight_t** createGraph(int n) {
	// int n; //vertex number
	// scanf("%d", &n);
	weight_t** amtx = (weight_t**)malloc(sizeof(weight_t*) * n);
	for (int i = 0; i < n; ++i)
		*(amtx + i) = (weight_t*)malloc(sizeof(weight_t) * n);
	fill(amtx[0], amtx[0] + n * n, 0);
	int v1, v2, m; // edge
	weight_t w = 1;
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &v1, &v2);
		// scanf("%d",&weight);//read weight
		amtx[v1][v2] = w; // unidirection graph
		amtx[v2][v1] = w; // nondirection
	}
	return amtx;
}
void showGraph(graph g, int n) {
	for (size_t i = 1; i < n; i++) {
		for (size_t j = 1; j < n; j++) {
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
}
int main(int argc, char const* argv[]) {
	int n;
	scanf("%d", &n);
	showGraph(createGraph(n+1), n+1);
	return 0;
}
