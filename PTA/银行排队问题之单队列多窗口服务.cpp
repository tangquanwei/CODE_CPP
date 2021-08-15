/** 
 * 银行排队问题之单队列多窗口服务
 * 用数组模拟队列(为了算时间)
 * 当队列中有人时:
 * 1.遍历窗口 
 *      若该窗口的完成时间<=顾客的到达时间
 *      则:
 *          1)更新该窗口的完成时间
 *          2)该窗口服务的人数++
 *          3)将这个人标记为不需要排队
 *          4)将给顾客弹出队列
 *          5)跳出遍历窗口的循环
 *      若须要等待(完成时间>到达时间(循环未跳出))
 *      则
 *          1)继续遍历
 *          2)记录各个窗口里最快完成的那个窗口的完成时间，和下标
 * 2.如果须要等待
 *      1)计算单次等待时间
 *      2)更新最长等待时间
 *      3)计算累计等待时间(为了求最后完成时间) 
 *      4)更新对应窗口的完成时间(继续遍历时找到的窗口)
 *      5)对应窗口人数++(关键)   
 *      6)将给顾客弹出队列   
 */
#include <bits/stdc++.h>
#define INF 65535
using namespace std;
int main() {
	int head, tail, n, k, i;
	scanf("%d", &n);
	vector<pair<int, int>> q(n);
	head = tail = 0; //队列头和尾
	for (i = 0; i < n; i++) {
		scanf("%d %d", &q[tail].first, &q[tail].second); //将输入的数入队列
		if (q[tail].second > 60)
			q[tail].second = 60; //最大处理时间60
		tail++;
	}
	scanf("%d", &k);						  //k个窗口
	int sumwait = 0, maxwait = 0, wait = 0;	  //总的等待时间， 最长的等待时间， 单次等待时间
	int finisht[k] = { 0 }, psnum[k] = { 0 }; //完成时间，窗口人数
	while (head < n) {
		int needNoWait = 0, tnim = INF, imin = 0;			 //标记变量， 最快的完成时间， 最快完成时间的下标
		for (i = 0; i < k; i++) {							 //遍历k个窗口
			if (finisht[i] <= q[head].first) {				 //完成时间<=到达时间，表明不须要等待
				finisht[i] = q[head].first + q[head].second; //更新完成这个窗口完成的时间
				psnum[i]++;									 //窗口人数加一
				needNoWait = 1;								 //不须要等待
				head++;
				break;
			}
			if (tnim > finisht[i]) { //若是须要等待，就记录各个窗口里最快完成的那个窗口的完成时间，和下标
				tnim = finisht[i];
				imin = i;
			}
		}
		if (!needNoWait) {				 //须要等待
			wait = tnim - q[head].first; //等待的时间，最快完成的时间减去队列第一到达的时间
			if (maxwait < wait)
				maxwait = wait;					   //不断更新等待的最长时间
			sumwait += wait;					   //求等待时间的和
			finisht[imin] = tnim + q[head].second; //更新对应窗口的完成时间
			psnum[imin]++;						   //对应窗口人数++
			head++;
		}
	}
	int last = accumulate(finisht, finisht + k, 0, [](int a, int b) {
		return max(a, b);
	}); //求最大完成时间
	printf("%.1lf %d %d\n", 1.0 * sumwait / n, maxwait, last);
	printf("%d", psnum[0]);
	for (i = 1; i < k; i++)
		printf(" %d", psnum[i]);
	return 0;
}