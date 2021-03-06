#include <iostream>

using namespace std;

// function-like class 仿函数

template <class T>
struct Identity
{
    const T &operator()(const T &x) const { return x; }
};
template <class Pair>
struct Select1st
{
    const typename Pair::first_type &
    operator()(const Pair &x) const { return x.first; }
};
template <class Pair>
struct Select2nd
{
    const typename Pair::second_type &
    operator()(const Pair &x) const { return x.second; }
};

template <class T1, class T2>
struct Pair
{
    T1 first;
    T2 second;
    pair() : first(T1()), second(T2()) {}
    pair(const T1 &a, const T2 &b) : first(a), second(b) {}
};

int main()
{
    return 0;
}