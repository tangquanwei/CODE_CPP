/* 救济金发放（The Dole Queue, UVa 133）
n(n<20)个人站成一圈，逆时针编号为1～n。有两个官员，A从1开始逆时针数，B从n开
始顺时针数。在每一轮中，官员A数k个就停下来，官员B数m个就停下来（注意有可能两个
官员停在同一个人上）。接下来被官员选中的人（1个或者2个）离开队伍。
输入n，k，m输出每轮里被选中的人的编号（如果有两个人，先输出被A选中的）。例
如，n=10，k=4，m=3，输出为4 8, 9 5, 3 1, 2 6, 10, 7。注意：输出的每个数应当恰好占3列。 */
#include <bits/stdc++.h>
#define maxn 25
int n, k, m, a[maxn];
//逆时针走t步，步长是d（-1表示顺时针走），返回新位置
int go(int p, int d, int t);
int main() {
	while (scanf("%d%d%d", &n, &k, &m) == 3 && n) {
		for (int i = 1; i <= n; i++)
			a[i] = i;
		int left = n; //还剩下的人数
		int p1 = n, p2 = 1;
		while (left) {
			p1 = go(p1, 1, k);
			p2 = go(p2, -1, m);
			printf("%3d", p1);
			left--;
			if (p2 != p1) {
				printf("%3d", p2);
				left--;
			}
			a[p1] = a[p2] = 0;
			if (left)
				printf(",");
		}
		printf("\n");
	}
	return 0;
}

int go(int p, int d, int t) {
	while (t--) {
		do {
			p = (p + d + n - 1) % n + 1;
		} while (a[p] == 0); //走到下一个非0数字
	}
	return p;
}