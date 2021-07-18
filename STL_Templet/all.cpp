#include <vector>
#include <list>
#include <algorithm>
#include <functional> //bind
#include <iostream>
#include <iterator>
#include <numeric>

using namespace std;
using namespace std::placeholders; // 占位符 _1, _2
template <typename T>
struct plus__ : public binary_function<T, T, bool> //继承3个 typedef
{
    T operator()(const T &x, const T &y) const
    {
        return x + y;
    }
}; // Functor

double multiply(double x, double y)
{
    return x * y;
}
namespace adaptor
{
    void test()
    {
        int ia[6] = {1, 3, 3, 4, 5, 6};
        int ib[4] = {10, 20, 30, 40};
        vector<int, allocator<int>> vi(ia, ia + 6);
        sort(vi.rbegin(), vi.rend()); //reverse
        for (auto &&i : vi)
        {
            cout << i << endl;
        }
        sort(vi.begin(), vi.begin() + 4);
        for (auto &&i : vi)
        {
            cout << i << endl;
        }
        cout << count_if(vi.begin(), vi.end(), bind(less<int>(), _1, 4)) << endl;
        int sum = accumulate(vi.begin(), vi.end(), 0, plus__<int>());
        cout << sum << endl;
        auto fn_1 = bind(multiply, _1, 5);
        cout << fn_1(6) << endl;
        auto fn_2 = bind(multiply, 5, _1);
        cout << fn_2(7) << endl;
    }
}
namespace iter_adapter
{
    /* iterator adapter */
    // inserter
    void test()
    {
        int ia[6] = {1, 3, 3, 4, 5, 6};
        vector<int, allocator<int>> vi(ia, ia + 6);
        vector<int> vi2(12);
        copy(ia, ia + 6, vi2.begin());
        for (auto &&i : vi2)
        {
            cout << i << ' ';
        }
        cout << endl;
        vector<int>::iterator it = vi2.begin() + 3;
        // advance(it,3); // list
        copy(vi.begin(), vi.end(), inserter(vi2, it));
        for (auto &&i : vi2)
        {
            cout << i << ' ';
        }
        cout << endl;

        list<int> foo, bar;
        for (int i = 1; i < 6; ++i)
        {
            foo.push_back(i);
            bar.push_back(i * 10);
        }
        list<int>::iterator it2 = foo.begin();
        advance(it2, 3);
        copy(bar.begin(), bar.end(), inserter(foo, it2));
        for (auto &&i : foo)
        {
            cout << i << " ";
        }
    }
}
namespace x_adpter
{
    void test1()
    {
        vector<int> vi;
        for (int i = 1; i < 10; ++i)
            vi.push_back(i * 10);
        ostream_iterator<int> out_it(cout, ", ");
        copy(vi.begin(), vi.end(), out_it);
    }
    void test2()
    {
        double v1, v2;
        cout << "Insert two values :";
        istream_iterator<double> eos;      //end_of_stream
        istream_iterator<double> iit(cin); //end_of_stream
        if (iit != eos)
            v1 = *iit;
        ++iit;
        if (iit != eos)
            v2 = *iit;
        cout << v1 << '*' << v2 << '=' << v1 * v2 << endl;
    }
    void test3()
    {
        vector<double> c;
        istream_iterator<double> iit(cin), eos; //! 已经开始读了
        // ?怎么退出
        copy(iit, eos, inserter(c, c.begin()));
    }
}
namespace template_
{
    /* 打印多个不同类型的值 */
    void print() {}                       // ! 必要 当print参数为零的时候调用
    template <class T, typename... Types> //? ...就是所谓的pack
    void print(const T &first_arg, const Types &...args)
    {
        cout << first_arg << endl;
        cout << "sizeof...(args) = " << sizeof...(args) << endl;
        // ? 返回pack member的个数
        print(args...); //* 递归 recursion
    }

    template <typename T>
    T add(T x, T y)
    {
        return x + y;
    }
    template <typename T>
    T operation(T x, T y, T (*func)(T, T))
    {
        return (*func)(x, y);
    }

    // 函数指针
    template <typename T>
    T (*add_1)
    (T, T) = add;
    // 指针函数
    template <typename T>
    T *add_2(T a, T b)
    {
        int *s = new T(a + b);
        return s;
    }
}

int main()
{
    x_adpter::test3();

    return 0;
}