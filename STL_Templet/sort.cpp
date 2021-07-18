#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>

template <typename T>
void sort_(T &v)
{
    std::sort(v.begin(), v.end(), [](auto first, auto second) -> bool
              { return first > second; });
}

template <class T, class alloc>
class Sort
{
public:
    void operator()(T &v)
    {
        std::sort(v.begin(), v.end(), [](auto first, auto second) -> bool
                  { return first > second; });
    }
};
struct Sort_
{
    void operator()(std::string &v)
    {
        std::sort(v.begin(), v.end(), [](auto first, auto second) -> bool
                  { return first > second; });
    }
};

int main()
{
    std::vector<int> vi{2, 1, 4, 3, 6, 5};
    std::vector<std::string, std::allocator<std::string>> vs{"ysdf", "zwer", "xswedc"};
    sort_(vi);
    for_each(vi.begin(), vi.end(), [](auto i)
             { std::cout << i << ' '; });
    sort_(vs);

    for_each(vs.begin(), vs.end(), [](auto i)
             { std::cout << i << ' '; });

    return 0;
}