#include <bits/stdc++.h>
/* 归并排序 */
namespace merge {
	int* aux;
	int less(int a, int b) { return a < b; }
	void merge_sort(int a[], int n) { //自顶向下
		aux = (int*)malloc(sizeof(int) * n);
		sort(a, 0, n - 1);
	}
	void sort(int a[], int lo, int hi) { //分
		if (hi <= lo)
			return;
		int mid = lo + (hi - lo) / 2;
		sort(a, lo, mid);
		sort(a, mid + 1, hi);
		merge(a, lo, mid, hi);
	}
	void merge(int a[], int lo, int mid, int hi) { //和
		int i = lo, j = mid + 1;
		for (int k = lo; k <= hi; ++k) {
			aux[k] = a[k];
		}
		for (int k = lo; k <= hi; ++k) {
			if (i > mid)				   //左半边用尽
				a[k] = aux[j++];		   //取右半边的元素
			else if (j > hi)			   //右半边用尽
				a[k] = aux[i++];		   //取左半边的元素
			else if (less(aux[j], aux[i])) //右边小于左边
				a[k] = a[j++];			   //取右边
			else						   //右边小于等于左边
				a[k] = aux[i++];		   //取左边
		}
	}
}