#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator> //back_inserter
#include <memory>

using namespace std;
void output(vector<int> v, ostream &os, char c = ' ')
{
    for_each(v.begin(), v.end(), [&os, c](const int x)
             { os << x << c; });
}
void output(int a[], int size, ostream &os = cout, char c = ' ')
{
    for_each(a, a + size, [&, c](const int x)
             { os << x << c; });
}

int main()
{
    // vector<int> v1;
    // auto it = back_inserter(v1);
    // fill_n(it, 10, 3);
    // for (auto &&i : v1)
    // {
    //     cout << i << "  ";
    // }
    // cout << endl;
    // auto end_unique = unique(v1.begin(), v1.end());
    // v1.erase(end_unique, v1.end());
    // for (auto &&i : v1)
    // {
    //     cout << i << "  ";
    // }

    // int a1[]{1, 2, 3, 2, 5, 6, 7, 8};
    // int a2[sizeof(a1) / sizeof(*a1)];
    // copy(begin(a1), end(a1), a2);
    // cout << endl;
    // for_each(a2, end(a2), [](auto x)
    //          { cout << x << ' '; });
    // cout << endl;
    // replace(a2, end(a2), 3, 3000);
    // output(a2, sizeof(a2) / sizeof(*a2));
    // output(a2, sizeof(a2) / sizeof(*a2));
    // cout << endl;
    // sort(a2, end(a2), [](const auto x, const auto y) -> bool
    //      { return x > y; });
    // cout << endl;
    // for_each(a2, end(a2), [](auto x) mutable
    //          {
    //              ++x; // 没有改变原值
    //              cout << x << ' ';
    //          });
    // cout << endl;
    // auto end_unique2 = unique(a2, end(a2));
    // int s = 3;
    // for_each(a2, end_unique2, [s](const auto x) -> double
    //          {
    //              if (x > s)
    //                  cout << x << ' ';
    //          });
    // auto f = [&s]
    // { return ++s; };
    // cout << f() << endl;
    
    shared_ptr<string> p1=make_shared<string>("Quanwei");//调用string的构造函数
    cout<<*p1<<endl;
    cout<<p1.use_count()<<endl;
    auto p2(p1);
    cout<<p1.use_count()<<endl;
    cout<<p2.use_count()<<endl;



    return 0;
}