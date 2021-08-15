#include <bits/stdc++.h>
using namespace std;

/* 
算法(输入同时判断):
0.定义标志 isHamilton
1.查询的节点数 == n+1 ? true : false
2.查询中的首节点编号 == 尾节点编号 ? true : false
3.查询中任意两相邻节点之间联通 ? true : false
4.顶点只访问 1 次 ? true : false
 */

// 数据量太大
bool graph[201][201]; //adjacency matrix
int main(int argc, char const* argv[]) {
	int n, m, k;
	scanf("%d%d", &n, &m);
	fill(graph[0], graph[0] + 201 * 201, false); // line-pointer
	int v1, v2;
	while (m--) {
		scanf("%d%d", &v1, &v2);
		graph[v1][v2] = graph[v2][v1] = true;
	}
	scanf("%d", &k);
	while (k--) {
		bool isHamilton = true;
		int num, v;
		vector<int> circle;
		scanf("%d", &num);
		for (int i = 0; i < num; ++i) {
			scanf("%d", &v);
			circle.push_back(v);
		}
		if (num != n + 1 || circle[0] != circle[circle.size() - 1]) {
			/* 查询的节点数不等于N+1,查询中的首节点编号不等于尾节点编号 */
			isHamilton = false;
		}
		else {
			set<int> record;
			record.insert(circle[0]);
			for (int i = 1; i < circle.size(); ++i) {
				if (!graph[circle[i - 1]][circle[i]]) {
					/* 查询中任意两相邻节点之间无通路 */
					isHamilton = false;
					break;
				}
				record.insert(circle[i]);
			}
			if (record.size() != n) { /* 顶点访问不只 1 次 */
				isHamilton = false;
			}
		}
		printf("%s\n", isHamilton ? "YES" : "NO");
	}
	return 0;
}
