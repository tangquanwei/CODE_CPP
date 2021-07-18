#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> twoSum(vector<int> v, int t)
{
    int i{0}, j{v.size() - 1}, sum;
    do
    {
        sum = *(v.begin() + i) + *(v.begin() + j);
        if (sum > t)
            j--;
        if (sum < t)
            i++;
    } while (sum != t);
    return vector<int>{i + 1, j + 1};
}
vector<int> mergeArray(vector<int> v1, int m, vector<int> v2, int n)
{
    auto pos = v1.size() - 1;
    --m;
    --n;
    while (m >= 0 && n >= 0)
    {
        v1[pos--] = v1[m] > v2[n] ? v1[m--] : v2[n--];
    }
    while (n >= 0)
    {
        v1[pos--] = v2[n--];
    }
    return v1;
}
vector<int> mergeArray_1(vector<int> v1, int m, vector<int> v2, int n)
{
    for (auto &&i : v2)
    {
        v1.push_back(i);
    }
    sort(v1.begin(), v1.end());
    return v1;
}
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow{head}, *fast{head};
    do
    {
        if (!fast || fast->next)
            return nullptr;
        fast = fast->next->next;
        slow = slow->next;

    } while (fast != slow);
    fast = head;
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}
int main()
{
    // vector<int> v1 = {2, 3, 4, 5, 0, 0, 0, 0};
    // vector<int> v2 = {3, 4, 5, 6};
    // int m{4}, n{4};
    // ;
    // for (auto &&i : mergeArray(v1, m, v2, n))
    // {
    //     cout << i << "  ";
    // }

    return 0;
}