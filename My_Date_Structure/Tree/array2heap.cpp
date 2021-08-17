#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const* argv[]) {
	int n = 10;
	int heap[n];
	heap[0] = INT_MIN;
	int size = 0;
	int i;
	int idx = 0;
	int a[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	while (n--) {
		for (i = ++size; a[n] < heap[i / 2]; i /= 2) {
			heap[i] = heap[i / 2];
		}
		heap[i] = a[n];
	}
	for (int i = 1; i <= size; ++i) {
		cout << heap[i] << " ";
	}

	return 0;
}
