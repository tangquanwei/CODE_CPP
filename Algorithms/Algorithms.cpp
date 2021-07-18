#include <vector>
#include <algorithm>
#include <iostream> // sort
#include <numeric>  // accumulate
using namespace std;
namespace greedy
// 贪心算法或贪心思想采用贪心的策略，保证每次操作都是局部最优的
// 从而使最后得到的结果是全局最优的
{

    /* 
题目描述
有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干都有一个大小。每个孩子只能吃
最多一个饼干，且只有饼干的大小大于孩子的饥饿度时，这个孩子才能吃饱。求解最多有多少孩
子可以吃饱。
输入输出样例
输入两个数组，分别代表孩子的饥饿度和饼干的大小。输出最多有多少孩子可以吃饱的数
量。
Input: [1,2], [1,2,3]
Output: 2
在这个样例中，我们可以给两个孩子喂 [1,2]、[1,3]、[2,3] 这三种组合的任意一种。
 */
    int findContentChildren(vector<int> &children, vector<int> &cookies)
    {
        sort(children.begin(), children.end());
        sort(cookies.begin(), cookies.end());
        int child = 0, cookie = 0;
        while (child < children.size() && cookie < cookies.size())
        {
            if (children[child] <= cookies[cookie])
                ++child;
            ++cookie;
        }
        return child;
    }

    /* 
题目描述
一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一
个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；所
有孩子至少要有一个糖果。求解最少需要多少个糖果。
输入输出样例
输入是一个数组，表示孩子的评分。输出是最少糖果的数量。
Input: [1,0,2]
Output: 5
 */
    int candy(vector<int> &ratings)
    {
        vector<int> vi(ratings.size(), 1);// (元素个数，初始值)
        for (int i = 1; i < ratings.size(); ++i)
        {
            if (ratings[i - 1] < ratings[i])
            {
                vi[i] = vi[i - 1] + 1;
            }
        }
        for (int i = ratings.size() - 1; i > 0; --i)
        {
            if (ratings[i - 1] > ratings[i])
            {
                vi[i - 1] = max(vi[i - 1], vi[i] + 1);
            }
        }
        return accumulate(vi.begin(), vi.end(), 0);
    }
}
int main()
{
    vector<int> vi1{1, 2, 3, 4},
        vi2{1, 2, 3};
    cout << greedy::findContentChildren(vi1, vi2) << endl;
    vector<int> vi3{1, 0, 5};
    cout << greedy::candy(vi3) << endl;

    return 0;
}